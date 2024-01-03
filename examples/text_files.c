#include <file.h>

/*
  Reading and writing example with normal text files
*/

int main()
{ 
  // Reading text
  h_file input = h_open_file("examples/data/read_me.txt");

  // Read the line and print it out to the screen
  while (!is_eof(input))
  {
    string ln = read_line(&input);

    printf("%s\n", ln.characters);

    // Strings do need to be freed
    free_string(&ln);
  }
  h_close_file(&input);

  // Writing and saving text
  h_file output = h_write_file("examples/data/out.txt");

  /*
    Writing can be done in two ways

      1. With the custom strings type: this allows for easier manipulation of data
      2. Simple char* for easier writing
  */

  // 1
  string str = create_string("Method 1");
  // write_line automatically adds the \n for you. write_string does not
  write_line(&output, str);
  free_string(&str);

  // 2
  write_chars(&output, "Method 2\n");

  h_close_file(&output);
  return 0;  
}