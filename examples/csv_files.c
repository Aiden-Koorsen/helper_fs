#include <csv.h>

int main()
{
  // Reading example
  h_csv input = h_open_csv("data/test_database.csv");

  while (!is_eof(input.f))
  {
    csv_row row = get_row(&input);

    free_csv_row(&row);
  }

  h_close_csv(&input);

  return 0;
}