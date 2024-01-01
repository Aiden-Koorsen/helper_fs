#include <str.h>

string create_string(char *c_str)
{
  string result;

  result.length = strlen(c_str);
  result.characters = malloc(result.length);

  strcpy(result.characters, c_str);

  if (result.characters == NULL)
  {
    printf("String Error: Couldn't create string!\n");
    free(result.characters);
    return result;
  } 

  return result;
}

void free_string(string *str)
{
  free(str->characters);
}

int find_string(string result, string src)
{
  for (int i = 0; i < src.length; i++)
  {
    if (i + result.length <= src.length)
    {
      if (strcmp(result.characters, src.characters + i))
        return i;
    }
    else
      return -1;
  }  
  return -1;
}

// Simple wrapper around C's method for now :(
int compare_strings(string str1, string str2)
{
  return strcmp(str1.characters, str2.characters);
}

int find_char(char result, string src)
{
  for (int i = 0; i < src.length; i++)
    if (src.characters[i] == result)
      return i;

  return -1;
}

int find_last_string(string result, string src)
{
  int index = -1;
  for (int i = 0; i < src.length; i++)
  {
    if (i + result.length <= src.length)
    {
      if (strcmp(result.characters, src.characters + i))
        index = i;
    }
    else
      return -1;
  }

  return -1;
}

int find_last_char(char result, string src)
{
  int index = -1;

  for (int i = 0; i < src.length; i++)
    if (src.characters[i] == result)
      index = i;

  return index;
}

string copy(string src)
{
  string result;
  result.length = src.length;
  result.characters = malloc(src.length);

  strcpy(result.characters, src.characters);

  if (result.characters == NULL)
    printf("String Error: Couldn't copy string\n");

  return result;
}

string copy_n(string src, int index, int count)
{
  if (index + count > src.length)
    printf("String Error: Trying to copy invaild memory\n");   

  string result;
  result.characters = malloc(count + 1);
  strncpy(result.characters, src.characters + index, count);

  result.characters[count] = '\0';
  result.length = count;

  if (result.characters == NULL)
    printf("String Error: Couldn't copy string\n");
  
  return result;
}