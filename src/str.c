#include <str.h>

/**
 * @brief Creates a new string
 * 
 * @param c_str The data you would like that string to hold 
 * @return string 
 */
string create_string(char *c_str)
{
  string result;

  result.length = strlen(c_str);
  result.characters = malloc(result.length + 1);

  strcpy(result.characters, c_str);
  result.characters[result.length] = '\0';

  if (result.characters == NULL)
  {
    printf("String Error: Couldn't create string!\n");
    free(result.characters);
    return result;
  } 

  return result;
}

/**
 * @brief Frees all the memory that the string holds
 * 
 * @param str A pointer to the string you would like to free 
 */
void free_string(string *str)
{
  free(str->characters);
}

/**
 * @brief Finds the position of a string inside another string  
 * 
 * @param result The string you are searching for
 * @param src The string you would like to search
 * @return int - The index where the string was found
 */
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

/**
 * @brief A wrapper for the strcmp function 
 * 
 * @param str1  
 * @param str2 
 * @return int - 0 = Same, 1 = str1 is greater, 2 = str1 is smaller
 */
int compare_strings(string str1, string str2)
{
  return strcmp(str1.characters, str2.characters);
}

/**
 * @brief Finds the position of a single character in a string 
 * 
 * @param result The character you are searching for
 * @param src The string you would like to search
 * @return int - The index where the character was found 
 */
int find_char(char result, string src)
{
  for (int i = 0; i < src.length; i++)
    if (src.characters[i] == result)
      return i;

  return -1;
}

/**
 * @brief Finds the position of a string that occurs last in another string 
 * 
 * @param result The string you are searching for
 * @param src The string you would like to search
 * @return int - The index where the last string was found
 */
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

/**
 * @brief Finds the position of a character that occurs last in a string
 * 
 * @param result The character you are searching for
 * @param src The string you would like to search
 * @return int - The index where the last chracter was found
 */
int find_last_char(char result, string src)
{
  int index = -1;

  for (int i = 0; i < src.length; i++)
    if (src.characters[i] == result)
      index = i;

  return index;
}

/**
 * @brief Creates a copy of another string 
 * 
 * @param src The string you would like to copy
 * @return string 
 */
string copy(string src)
{
  string result;
  result.length = src.length;
  result.characters = malloc(src.length + 1);

  strcpy(result.characters, src.characters);
  result.characters[result.length] = '\0';

  if (result.characters == NULL)
    printf("String Error: Couldn't copy string\n");

  return result;
}

/**
 * @brief Copies a certain amount of characters from a string starting at a certain position 
 * 
 * @param src The string you would like to copy
 * @param index The offset within the string to copy from
 * @param count The amount of characters you would to copy
 * @return string 
 */
string copy_n(string src, int index, int count)
{
  // if (index + count > src.length)
    // printf("String Error: Trying to copy invaild memory\n");   

  string result;
  result.characters = malloc(count + 1);
  strncpy(result.characters, src.characters + index, count);

  result.characters[count] = '\0';
  result.length = count;

  if (result.characters == NULL)
    printf("String Error: Couldn't copy string\n");
  
  return result;
}

/**
 * @brief Finds the number of times a character appears in a string
 * 
 * @param desired The character you are counting
 * @param src The string you are searching through
 * @return int 
 */
int find_char_occurence(char desired, string src)
{
  int result = 0;

  for (int i = 0; i < src.length; i++)
    if (src.characters[i] == desired)
      result++;

  return result;
}

/**
 * @brief Deletes some chracters from a string 
 * 
 * @param orignal The string you want to manipulate 
 * @param index Index for the first character
 * @param count The amount of characters you want to delete
 */

void delete_characters(string *orignal, int index, int count)
{
  string before = copy_n(*orignal, 0, index);
  string after = copy_n(*orignal, index + count, orignal->length - index); 

  free_string(orignal);

  orignal->characters = malloc(before.length + after.length + 1);
  strcpy(orignal->characters, before.characters);
  strcpy(orignal->characters + before.length, after.characters);
  orignal->characters[before.length + after.length] = '\0';
  orignal->length = strlen(orignal->characters);

  free_string(&before);
  free_string(&after);
}

/**
 * @brief Adds two strings together and returns the result 
 * 
 * @param str1 First string  
 * @param str2 Second string
 * @return string 
 */
string add_strings(string str1, string str2)
{
  string result;

  result.characters = malloc(str1.length + str2.length + 1);

  strcpy(result.characters, str1.characters);
  strcpy(result.characters + str1.length, str2.characters);
  result.characters[str1.length + str2.length] = '\0';

  return result;
}
