#include <stdio.h>
#include <x86intrin.h>
#include "../src/matarith.h"
#include "../src/mattranspose.h"
#include "../src/fastfibo.h"

#define NRUN 100
#define N    10
#define max(a,b) (a>b)? a:b
#define fib(n) ({unsigned long long f[2] = {1,1};for(int i = 3; i <= n; i++){f[1] = f[0]+f[1];f[0]=f[1]-f[0];};f[1];})

typedef int mat[N*N] __attribute__((aligned(32)));

#pragma pack(4)
typedef struct
{
  // pragma pack(1)
  // | 1 | (char)
  // | 1 | (int 1)
  // | 2 | (int 2)
  //  . . . 

  // pragma pack(2)
  // | 1 | 2 | (char)
  // | 1 | 2 | (int 1)
  // | 3 | 4 | (int 2)
  // . . . 

  // pragma pack(4)
  // | 1 | 2 | 3 | 4 | (char)
  // | 1 | 2 | 3 | 4 | (int)
  // | 1 | 2 | 3 | 4 | (long long int 1)
  // | 5 | 6 | 7 | 8 | (long long int 2)
  // . . .

  char c;          // | 1 |   |   |   |   |   |   |   |
  char c1;         // | 1 |
  char c2;         // | 1 |
  char c3;         // | 1 |
  char c4;         // | 1 |

  int a;           // | 1 | 2 | 3 | 4 |   |   |   |   |
  long long int b; // | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |

}uni_t, *uni[1];


//void basla(void) __attribute__((constructor)); // Programın başında main'den önce çalıştır.
//void bitir(void) __attribute__((destructor)); // Programın sonunda main'den çıkınca çalıştır.

__attribute__((constructor (101))) void basla(void); // Programın başında main'den önce çalıştır.
__attribute__((constructor (102))) void baslayabilir_misin(void); // Programın başında main'den önce çalıştır.
__attribute__((destructor)) void bitir(void); // Programın sonunda main'den çıkınca çalıştır.s

void basla(void) {
  printf("Bana emir verme.\n");
}

void baslayabilir_misin(void){
  printf("Tamamdır, Program başladı.\n");
}

void bitir(void){
  printf("Program bitti.\n");
}

int matrix_compare(const int* m1, const int* m2, int row_count, int col_count)
{
  int i, j, index;

  for(i = 0; i < row_count; i++){
    for(j = 0; j < col_count; j++){
      index = i * col_count + j;
      if(m1[index] != m2[index]){
        return 1;
      }
    }
  }
  return 0;
}

void print_matrix(const int* m, int row_count, int col_count)
{
  int i, j;
  for(i = 0; i < row_count; i++){
    for(j = 0; j < col_count; j++){
      printf("%d ", m[i * col_count + j]);
    }
    printf("\n");
  }
  printf("\n");
}

int matrix_test()
{
  int m1[] = {1, 2, 3, 4, 5, 6};
  int m2[] = {7, 8, 9, 10, 11, 12};

  int m1_row_count = 2;
  int m1_col_count = 3;
  int m2_row_count = 3;
  int m2_col_count = 2;

  if(m1_col_count == m2_col_count && m1_row_count == m2_row_count){
    int m3[4];
    int m4[] = {3, 5, 7, 9};
    matrix_add(m3, m1, m2, m1_row_count, m1_col_count);
    printf("Matrix Toplam Sonucu:\n");
    print_matrix(m3, m1_row_count, m1_col_count);
    if(matrix_compare(m3, m4, m1_row_count, m1_col_count) != 0){
      printf("TOPLAMADA HATA!\n\n");
    }

    int m5[4];
    int m6[] = {-1, -1, -1 , -1};
    matrix_sub(m5, m1, m2, m1_row_count, m1_col_count);
    printf("Matrix Çıkarma Sonucu:\n");
    print_matrix(m5, m1_row_count, m1_col_count);
    if(matrix_compare(m5, m6, m1_row_count, m1_col_count) != 0){
      printf("ÇIKARMADA HATA!\n\n");
    }
  }else{
    printf("Matris Boyutları Farklı! Toplama veya çıkarma yapılamaz. m1: [%d, %d]  m2: [%d, %d]\n", m1_row_count, m1_col_count, m2_row_count, m2_col_count);
  }

  if(m1_col_count == m2_row_count){
    int m7[1];
    matrix_mul(m7, m1, m2, m1_col_count, m1_row_count, m2_col_count);
    printf("Matrix Çarpım Sonucu:\n");
    print_matrix(m7, m1_row_count, m2_col_count);
  }else{
    printf("Matrisler çarpılabilir değil!  m1: [%d, %d]  m2: [%d, %d]\n\n", m1_row_count, m1_col_count, m2_row_count, m2_col_count);
  }
  return 0;
}

void generate_matrix(int* m, int row_count, int col_count)
{
  for(int i = 0; i < row_count; i++){
    for(int j = 0; j < col_count; j++){
      m[i * col_count + j] = j;
    }
  }
}

static inline unsigned long long __fibo__(int n){
  unsigned long long f[2] = {1,1};
  for(int i = 3; i <= n; i++){f[1] = f[0]+f[1];f[0]=f[1]-f[0];}
  return f[1];
}

int main(void)
{
  uni_t a1;
  uni b1;
  printf("sizeof(a1) = %ld \t sizeof(b1) = %ld\n", sizeof(a1), sizeof(b1));

  int i;

  int m1_row_count = N;
  int m1_col_count = N;
  int m2_row_count = N;
  int m2_col_count = N;

  // Windows'ta dizi tanımlarken
  //   int __declspec( align(32) ) dizi[N]

  // Linux'ta dizi tanımlarken
  //   int dizi[N] __attribute__(( aligned(32) ))


  mat m1;
  generate_matrix(m1, m1_row_count, m1_col_count);
  mat m2;
  generate_matrix(m2, m2_row_count, m2_col_count);

  mat m3;
  mat m4;
  mat m7;
  
  unsigned long long int c[3 * NRUN];
  for(i = 0; i < NRUN; i++){
    // MUL
    c[i*3] = _rdtsc();
    matrix_mul(m7, m1, m2, m1_col_count, m1_row_count, m2_col_count);
    c[i*3] = _rdtsc() - c[i*3];
    // ADD
    c[i*3+1] = _rdtsc();
    matrix_add(m3, m1, m2, m1_row_count, m1_col_count);
    c[i*3+1] = _rdtsc() - c[i*3+1];
    // SUB
    c[i*3+2] = _rdtsc();
    matrix_sub(m4, m1, m2, m1_row_count, m1_col_count);
    c[i*3+2] = _rdtsc() - c[i*3+2];
  }

  //print_matrix(m3, m1_row_count, m1_col_count);
  //print_matrix(m4, m1_row_count, m1_col_count);
  //print_matrix(m7, m1_row_count, m2_col_count);

  unsigned long long int mulTotalTime = 0;
  unsigned long long int addTotalTime = 0;
  unsigned long long int subTotalTime = 0;

  for(i = 0; i < NRUN; i++){
    mulTotalTime += c[i*3];
    addTotalTime += c[i*3+1];
    subTotalTime += c[i*3+2];
  }

  printf("Carpma Islemi Toplam zaman: \t%f\n", (double)mulTotalTime/NRUN);
  printf("Toplama Islemi Toplam zaman: \t%f\n", (double)addTotalTime/NRUN);
  printf("Cikarma Islemi Toplam zaman: \t%f\n", (double)subTotalTime/NRUN);

  mat m8;
  matrix_transpose(m8, m1, m1_row_count, m1_col_count);

  printf("\n");
  
  printf("Original Matrix:\n");
  print_matrix(m1, m1_row_count, m1_col_count);

  printf("Transposed Matrix:\n");
  print_matrix(m8, m1_col_count, m2_row_count);

  printf("Fib: %lld\nFibo: %lld\nFibonacci: %lld\n", fib(50), fibo(50), __fibo__(50));

  return 0;
}

// Compile with:
// gcc -o test_madd src/matharith.c test/matrix_test.c -Wall -O3 -march=native && ./test_madd
