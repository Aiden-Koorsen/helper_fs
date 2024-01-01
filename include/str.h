#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int compare_strings(string str1, string str2);

string copy(string src);
string copy_n(string src, int index, int count);

#endif