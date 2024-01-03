/**
 * @file csv.h
 * @author Aiden Koorsen
 * @brief Allows for reading and writing of CSV files
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright MIT License
 * 
 */

#ifndef CSV_H
#define CSV_H

#include <file.h>

/**
 * @brief This is a row in a csv file 
 * @param data This is an array of strings which will represent each column from the csv row  
 * @param count This is the amount of elements that exist in the row
 */
typedef struct
{
  string *data;
  int count;
} csv_row;

void free_csv_row(csv_row *r);

/**
 * @brief CSV file structure 
 * 
 * @param fp A pointer to C's base file structure
 * @param name A string for the name of the file
 * @param success Indicates that the file was successfully read
 */
typedef struct
{
  h_file f;
  string name;
  bool success;
}h_csv;

h_csv h_open_csv(const char *path);
void h_close_csv(h_csv *f);

csv_row get_row(h_csv *f);

#endif