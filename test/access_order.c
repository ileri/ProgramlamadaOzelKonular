#include <stdio.h>
#include <x86intrin.h>
#define N (1<<12)
#define STEP 4

/*
RAM -> L3 Cache -> L2 Cache -> L1 Cache -> CPU
*/

int main(void){
  //int a[N*N], b[N*N], c[N*N];
  int *a, *b, *c;
  a = (int*)malloc(4LL* N * N);
  b = (int*)malloc(4LL* N * N);
  c = (int*)malloc(4LL* N * N);

  int i, j, n, k;
  long long int at0, at1, bt0, bt1, ct0, ct1;

  for(n = 1; n <= N; n<<=1){

    at0 = _rdtsc();
    for(k = 0; k <= 16; k++){
      // Satırda sıralı erişim
      for(i = 0; i < n; i++){
        for(j = 0;j < n; j+=STEP){
          a[i * n + j] = j;
        }
        /*
        for(j = 0;j < n; j++){
          a[i * n + j] = j;
        }
        */
      }
    }
    at1 = _rdtsc() - at0;

    bt0 = _rdtsc();
    for(k = 0; k <= 16; k++){
      // Sütunda Sıralı Erişim
      for(i = 0; i < n; i += STEP){
        for(j = 0;j < n; j++){
          b[j * n + i] = i;
        }
      }
      /*
      for(i = 0; i < n; i++){
        for(j = 0;j < n; j++){
          b[j * n + i] = i;
        }
      }
      */
    }
    bt1 = _rdtsc() - bt0;

    ct0 = _rdtsc();
    for(k = 0; k <= 16; k++){
      // Rastgele Sıralı Erişim
      for(i = 0; i < n; i++){
        for(j = 0;j < n; j+=STEP){
          //c[rand() % ((n)*(n))] = j;
          c[((long long int)(rand() % (n * n))) & 0xfffffff0] = j;
        }
        /*
        for(j = 0;j < n; j++){
          c[rand() % ((n)*(n))] = j;
        }
        */
      }
    }
    ct1 = _rdtsc() - ct0;
    printf("%lld (%.2f), %lld (%.2f), %lld (%.2f);\n", at1, (double)at1/at1, bt1, (double)bt1/at1, ct1,(double)ct1/at1);
  }

  return 0;
}