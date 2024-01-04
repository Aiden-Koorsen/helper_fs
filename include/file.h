/**
 * @file file.h
 * @author Aiden Koorsen
 * @brief Reading and writing with custom strings for default files
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright MIT License
 * 
 */

#ifndef FILE_H
#define FILE_H

#include <str.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief The new and improved structure file reading and writing 
 * @param fp Pointer to original file
 * @param name The name of the file
 * @param success This boolean will allow you to test if the file has successfully read
 */
typedef struct 
{
  FILE *fp;
  string name;
  bool success;
} h_file;

string get_filename(string path);

h_file h_open_file(const char *path);
h_file h_write_file(const char *path);
void h_close_file(h_file *f);

string read_characters(h_file *f, int number);
string read_line(h_file *f);

bool is_eof(h_file f);

void write_string(h_file *f, string str);

void write_line(h_file *f, string ln);
void write_chars(h_file *f, char *data);
void write_char(h_file *f, char c);

#endif