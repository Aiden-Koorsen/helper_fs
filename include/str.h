/**
 * @file str.h
 * @author Aiden Koorsen
 * @brief Contains a custom string type
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright MIT License
 * 
 */
#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief A custom string data type 
 * @param characters A pointer to an actual C-string
 * @param length The length of the string
 */
typedef struct 
{
  char *characters;
  int length;
} string;

/**
 * @brief Creates a new string
 * 
 * @param c_str The data you would like that string to hold 
 * @return string 
 */
string create_string(char *c_str);

/**
 * @brief Frees all the memory that the string holds
 * 
 * @param str A pointer to the string you would like to free 
 */
void free_string(string *str);

/**
 * @brief Finds the position of a string inside another string  
 * 
 * @param result The string you are searching for
 * @param src The string you would like to search
 * @return int - The index where the string was found
 */
int find_string(string result, string src);

/**
 * @brief Finds the position of a single character in a string 
 * 
 * @param result The character you are searching for
 * @param src The string you would like to search
 * @return int - The index where the character was found 
 */
int find_char(char result, string src);

/**
 * @brief Finds the position of a string that occurs last in another string 
 * 
 * @param result The string you are searching for
 * @param src The string you would like to search
 * @return int - The index where the last string was found
 */
int find_last_string(string result, string src);

/**
 * @brief Finds the position of a character that occurs last in a string
 * 
 * @param result The character you are searching for
 * @param src The string you would like to search
 * @return int - The index where the last chracter was found
 */
int find_last_char(char result, string src);

/**
 * @brief A wrapper for the strcmp function 
 * 
 * @param str1  
 * @param str2 
 * @return int - 0 = Same, 1 = str1 is greater, 2 = str1 is smaller
 */
int compare_strings(string str1, string str2);

/**
 * @brief Creates a copy of another string 
 * 
 * @param src The string you would like to copy
 * @return string 
 */
string copy(string src);

/**
 * @brief Copies a certain amount of characters from a string starting at a certain position 
 * 
 * @param src The string you would like to copy
 * @param index The offset within the string to copy from
 * @param count The amount of characters you would to copy
 * @return string 
 */
string copy_n(string src, int index, int count);

#endif