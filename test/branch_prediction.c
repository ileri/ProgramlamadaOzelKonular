#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>


#define N (1<<20)

static int cmp_int(const void *a, const void *b){
  if(*(int *)a < *(int *)b) return -1;
  if(*(int *)a > *(int *)b) return 1;
  return 0;
}

int main(void){
  int* a;
  a = (int*)malloc(4 * N);
  int i, k, sum = 0;

  long long int at1 = 0LL;

  for(k = 0; k < 16; k++){
    for(i = 0; i < N; i++){
      a[i] = (rand() % 3) - 1;
    }
  }

  long long int at0 = _rdtsc();
  for(i = 0; i < N; i++){
    if(a[i] == 1){
      sum++;
    }
  }
  at1 += __rdtsc() - at0;

  printf("Karışık : %d: %lld\n", sum, at1>>4);


  at1 = 0LL;
  sum = 0;

  for(k = 0; k < 16; k++){
    for(i = 0; i < N; i++){
      a[i] = (rand() % 3) - 1;
    }
  }

  qsort(a, N, sizeof(int), cmp_int);
  
  at0 = _rdtsc();
  for(i = 0; i < N; i++){
    if(a[i] == 1){
      sum++;
    }
  }
  at1 += __rdtsc() - at0;

  printf("Sıralı :  %d: %lld\n", sum, at1>>4);
  return 0;
}