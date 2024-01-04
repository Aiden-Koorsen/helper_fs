#include <csv.h>

/**
 * @brief Opens and allows you to read data from a CSV file 
 * 
 * @param path The path to the CSV file
 * @return h_csv 
 */
h_csv h_open_csv(const char *path)
{
  h_csv result;

  result.f = h_open_file(path);

  if (result.f.success == false)
  {
    result.success = false;

    h_close_file(&result.f);
    return result;
  }

  string f_n = create_string((char*)path);
  result.name = get_filename(f_n);
  free_string(&f_n);

  result.success = true;
  return result;
}

/**
 * @brief Closes and frees all memory that the structure uses 
 * 
 * @param f A pointer to the file
 */
void h_close_csv(h_csv *f)
{
  h_close_file(&f->f);
}

/**
 * @brief Gets a new row from the file
 * 
 * @param f The pointer to the file 
 * @return csv_row 
 */
csv_row get_row(h_csv *f)
{
  csv_row result;

  string ln = read_line(&f->f);
  result.count = find_char_occurence(',', ln) + 1; 

  // Find and store all comma positions
  int commas[result.count];
  int index = 0;

  string dup = copy(ln);
  while (true)
  {
    int loc = find_char(',', dup);

    if (loc == -1)
      break;

    commas[index] = loc;
    index++;

    delete_characters(&dup, 0, loc + 1);
  } 

  // Allocate memory needed
  result.data = malloc(sizeof(string) * result.count);

  // Get and write all memory to row
  for (int i = 0; i < index; i++)
  {
    if (i == 0)
      result.data[i] = copy_n(ln, 0, commas[0]);
    else 
      result.data[i] = copy_n(ln, commas[i - 1] + 1, commas[i]);
  }

  // Get last element
  result.data[index] = copy(dup);

  // Free strings after use
  free_string(&ln);
  free_string(&dup);

  return result;
}

/**
 * @brief Create a CSV Row
 * 
 * @param count The amount of columns
 * @param data An array with the same count as the count argument that contains the values
 * @return csv_row 
 */
csv_row create_new_row(int count, string *data)
{
  csv_row result;

  result.count = count;
  result.data = malloc(sizeof(string) * count);

  for (int i = 0; i < count; i++)
  {
    result.data[i] = copy(data[i]);
  }

  return result;
}

/**
 * @brief Frees all memory that is used by a row 
 * 
 * @param r A pointer to the row
 */
void free_csv_row(csv_row *r)
{
  // Free each string
  for (int i = 0; i < r->count; i++)
    free_string(&r->data[i]);

  free(r->data);
}

/**
 * @brief Opens and allows you to write to a CSV File
 * 
 * @param path Path to the file 
 * @return h_csv 
 */
h_csv h_write_csv(const char *path)
{
  h_csv result;

  result.f = h_write_file(path);
  result.success = result.f.success;
  return result;
}

/**
 * @brief Writes a row to a CSV file
 * 
 * @param f Pointer to the CSV File 
 * @param new_row The new row you would like to add
 */
void write_row(h_csv *f, csv_row new_row)
{
  for (int i = 0; i < new_row.count; i++)
  {
    write_string(&f->f, new_row.data[i]);
    if (i != new_row.count - 1)
    {
      write_char(&f->f,',');
    }
  }
  write_char(&f->f,'\n');
}