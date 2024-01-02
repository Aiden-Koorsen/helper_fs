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
} helper_file;

/**
 * @brief Get the filename object
 * 
 * @param path Path to file you want to extract the file from
 * @return string
 */
string get_filename(string path);

/**
 * @brief Opens a file and allows you to read it
 * 
 * @param path Path to file 
 * @return helper_file 
 */
helper_file h_open_file(const char *path);

/**
 * @brief Opens a file and allow you to write to it 
 * 
 * @param path Path to file 
 * @return helper_file 
 */
helper_file h_write_file(const char *path);

/**
 * @brief Closes and cleans up memory of the file 
 * 
 * @param f A pointer to the helper_file 
 */
void h_close_file(helper_file *f);

/**
 * @brief Reads a certain number of characters from a file 
 * 
 * @param f A pointer to the file 
 * @param number The number of characters you want to read
 * @return string 
 */
string read_characters(helper_file *f, int number);

/**
 * @brief Reads 1 line from a file 
 * 
 * @param f A pointer to the file 
 * @return string 
 */
string read_line(helper_file *f);

/**
 * @brief Indicates if the file has been read completely or not 
 * 
 * @param f A pointer to the file 
 * @return true/
 * @return false 
 */
bool is_eof(helper_file f);

/**
 * @brief Writes a string to the file
 * 
 * @param f A pointer to the file 
 * @param str The data you would like to write to
 */
void write_string(helper_file *f, string str);

/**
 * @brief Write a stirng to the file with a \n 
 * 
 * @param f A pointer to the file 
 * @param ln The data you would like to write without a \n
 */
void write_line(helper_file *f, string ln);

/**
 * @brief Writes a c string to the file, this is sometimes better because with string, you need to free the memory after 
 * 
 * @param f A pointer to the file 
 * @param data The data you would like to write to
 */
void write_chars(helper_file *f, char *data);

#endif