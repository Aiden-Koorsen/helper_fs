#include <csv.h>

int main()
{
  // Reading example
  // h_csv input = h_open_csv("data/test_database.csv");

  // while (!is_eof(input.f))
  // {
  //   csv_row row = get_row(&input);
  //   // Print the output
  //   for (int i = 0; i < row.count; i++)
  //     printf("%s\n", row.data[i].characters);

  //   free_csv_row(&row);
  // }

  // h_close_csv(&input);

  // Writing example
  h_csv output = h_write_csv("data/output_database.csv");

  string data[3];

  data[0] = create_string("Row1");
  data[1] = create_string("Row2");
  data[2] = create_string("Row3");

  csv_row new_row = create_new_row(3, data);

  write_row(&output, new_row);
  free_csv_row(&new_row);

  for (int i = 0; i < 3; i++)
    free_string(&data[i]);

  h_close_csv(&output);

  return 0;
}