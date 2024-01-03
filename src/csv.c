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
  free_string(&f->name); 
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
 * @brief Frees all memory that is used by a row 
 * 
 * @param r 
 */
void free_csv_row(csv_row *r)
{
  // Free each string
  for (int i = 0; i < r->count; i++)
    free_string(&r->data[i]);

  free(r->data);
}