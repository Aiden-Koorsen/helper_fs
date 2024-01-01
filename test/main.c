#include <file.h>

int main()
{
  helper_file f = h_open_file("hello.txt");

  for (int i = 0; i < 4; i++)
  {
    string test = read_line(&f);

    printf("%s\n", test.characters);
    
    free_string(&test);
  }

  h_close_file(&f);
  return 0;
}