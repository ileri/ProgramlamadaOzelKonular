#include <stdio.h>
#include "../src/matarith.h"

typedef struct mata {
  int type;

  int (*matrix_add)(int* out_matrix, const int *m1, const int *m2, int row_count, int col_count);
  int (*matrix_sub)(int* out_matrix, const int *m1, const int *m2, int row_count, int col_count);
  int (*matrix_mul)(int* out_matrix, int* m1, int* m2, int m1_col_count, int row_count, int m2_col_count);
} mata;

void add(int a, int b){
  printf("a + b = %d\n", a+b);
}

void sub(int a, int b){
  printf("a - b = %d\n", a-b);
}

void mul(int a, int b){
  printf("a / b = %f\n", (double)a/(double)b);
}
void (*islem[])(int a, int b) = {add, sub, mul};

int main(void){
  mata mat1, mat2;

  int a = 5, b = 10;

  for(int i = 0; i < 3; i++){
    // Aman Allah'ım :O
    // C dilinde böyle bir şey de mi varmış o.O
    // Daha neler göreceğiz kim bilir :)
    (*islem[i])(a, b);
  }
}