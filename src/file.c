#include <file.h>

/**
 * @brief Opens a file and allows you to read it
 * 
 * @param path Path to file 
 * @return h_file 
 */
h_file h_open_file(const char *path)
{
  h_file result;

  result.fp = fopen(path, "r");

  if (result.fp == NULL)
  {
    printf("Helper FS: Error, file cannot open.\n");
    result.success = false;

    fclose(result.fp);
    return result;
  }
    string f_n = create_string((char*)path);
    result.name = get_filename(f_n);
    free_string(&f_n);

  result.success = true;

  return result;
}

/**
 * @brief Closes and cleans up memory of the file 
 * 
 * @param f A pointer to the h_file 
 */
void h_close_file(h_file *f)
{
  free_string(&f->name);
  fclose(f->fp);
}

/**
 * @brief Get the filename object
 * 
 * @param path Path to file you want to extract the file from
 * @return string
 */
string get_filename(string path)
{
  // First find last slash position
  int last_slash = find_last_char('/', path);

  if (last_slash == -1)
  {
    return copy(path);
  }
  else
  {
   return copy_n(path, last_slash, path.length - last_slash - 1);
  }
}

/**
 * @brief Reads a certain number of characters from a file 
 * 
 * @param f A pointer to the file 
 * @param number The number of characters you want to read
 * @return string 
 */
string read_characters(h_file *f, int number)
{
  char data[number + 1];

  for (int i = 0; i < number; i++)
    data[i] = fgetc(f->fp);
  
  data[number] = '\0';

  return create_string(data);
}

/**
 * @brief Reads 1 line from a file 
 * 
 * @param f A pointer to the file 
 * @return string 
 */
string read_line(h_file *f)
{
  // NOTE - This means that we are limited to 500 characters per line
  char data[500];

  fgets(data, 500, f->fp);

  string str = create_string(data);

  if (find_char('\n', str) != -1)
    str.characters[find_char('\n', str)] = '\0';

  return str;
}

/**
 * @brief Opens a file and allow you to write to it 
 * 
 * @param path Path to file 
 * @return h_file 
 */
h_file h_write_file(const char *path)
{
  h_file result;

  result.fp = fopen(path, "w");

  string n = create_string((char*)path);
  result.name = get_filename(n);
  free_string(&n);

  result.success = true;

  return result;
}

/**
 * @brief Writes a string to the file
 * 
 * @param f A pointer to the file 
 * @param str The data you would like to write to
 */
void write_string(h_file *f, string str)
{
  fprintf(f->fp, "%s", str.characters);
}

/**
 * @brief Writes a c string to the file, this is sometimes better because with string, you need to free the memory after 
 * 
 * @param f A pointer to the file 
 * @param data The data you would like to write to
 */
void write_chars(h_file *f, char *data)
{
  fprintf(f->fp, "%s", data);
}

/**
 * @brief Writes a single character to a file
 * 
 * @param f The pointer to the file 
 * @param c The character you would like to write
 */
void write_char(h_file *f, char c)
{
  putc(c, f->fp);
}

/**
 * @brief Write a stirng to the file with a \n 
 * 
 * @param f A pointer to the file 
 * @param ln The data you would like to write without a \n
 */
void write_line(h_file *f, string ln)
{
  fprintf(f->fp, "%s\n", ln.characters);
}

/**
 * @brief Indicates if the file has been read completely or not 
 * 
 * @param f A pointer to the file 
 * @return true/
 * @return false 
 */
bool is_eof(h_file f)
{
  return feof(f.fp);
}