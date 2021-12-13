#include <stdio.h>

#define RSIZE 128
#define CSIZE 128

int main(void){
  int box[RSIZE][CSIZE];
  int row_num, column_num;

  for(row_num = 0; row_num < RSIZE; row_num++)
    for(column_num = 0; column_num < CSIZE; column_num++)
      box[row_num][column_num] = column_num + (row_num * CSIZE);

  for(row_num = 0; row_num < RSIZE; row_num++)
    {
      for(column_num = 0; column_num < CSIZE; column_num++)
        {
          printf("%4d", box[row_num][column_num]);
        }
      printf("\n");
    }
  return 0;
}
