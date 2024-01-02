#ifndef FILE_H
#define FILE_H

#include <str.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
  FILE *fp;
  string name;
  bool success;
} helper_file;

string get_filename(string path);

helper_file h_open_file(const char *path);
helper_file h_write_file(const char *path);
void h_close_file(helper_file *f);

string read_characters(helper_file *f, int number);
string read_line(helper_file *f);

bool is_eof(helper_file f);

void write_string(helper_file *f, string str);
void write_line(helper_file *f, string ln);
void write_chars(helper_file *f, char *data);

#endif