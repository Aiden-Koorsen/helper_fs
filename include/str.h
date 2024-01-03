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


string create_string(char *c_str);
void free_string(string *str);

int find_string(string result, string src);
int find_char(char result, string src);
int find_last_string(string result, string src);
int find_last_char(char result, string src);
int find_char_occurence(char desired, string src);

int compare_strings(string str1, string str2);

string copy(string src);
string copy_n(string src, int index, int count);

void delete_characters(string *orignal, int index, int count);

#endif