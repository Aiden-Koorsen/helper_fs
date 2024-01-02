#include <file.h>

// Opens a file
helper_file h_open_file(const char *path)
{
  helper_file result;

  result.fp = fopen(path, "r");

  if (result.fp == NULL)
  {
    printf("Helper FS: Error, file cannot open.\n");
    result.success = false;

    fclose(result.fp);
    return result;
  }
    string f_n = create_string(path);
    result.name = get_filename(f_n);
    free_string(&f_n);

  result.success = true;

  return result;
}

void h_close_file(helper_file *f)
{
  free_string(&f->name);
  fclose(f->fp);
}

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

string read_characters(helper_file *f, int number)
{
  char data[number + 1];

  for (int i = 0; i < number; i++)
    data[i] = fgetc(f->fp);
  
  data[number] = '\0';

  return create_string(data);
}

// NOTE: 500 characters is the imposed limit at the moment
// This also automatically removes the new line chracter
string read_line(helper_file *f)
{
  char data[500];

  fgets(data, 500, f->fp);
  
  string str = create_string(data);

  if (find_char('\n', str) != -1)
    str.characters[find_char('\n', str)] = '\0';

  return str;
}

helper_file h_write_file(const char *path)
{
  helper_file result;

  result.fp = fopen(path, "w");

  string n = create_string(path);
  result.name = get_filename(n);
  free_string(&n);

  result.success = true;

  return result;
}

void write_string(helper_file *f, string str)
{
  fprintf(f->fp, "%s", str.characters);
}

void write_chars(helper_file *f, char *data)
{
  fprintf(f->fp, "%s", data);
}

void write_line(helper_file *f, string ln)
{
  fprintf(f->fp, "%s\n", ln.characters);
}

bool is_eof(helper_file f)
{
  return feof(f.fp);
}