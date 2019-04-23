#include <stdio.h>
#include <stdlib.h>
#include "../src/stackproc.h"

void hanoi(){
  int *s0;
  int *s1;
  int *s2;
  
  s0 = (int*)malloc(4 * sizeof(int)); *s0 = 255;
  s1 = (int*)malloc(4 * sizeof(int)); *s1 = 255;
  s2 = (int*)malloc(4 * sizeof(int)); *s2 = 255;

  *(++s0) = 3;
  *(++s0) = 2;
  *(++s0) = 1;

  printf("\nİLK:\n");
  print_hanoi_towers(s0, s1, s2);

  move(&s0, &s2);
  move(&s0, &s1);
  move(&s2, &s1);
  move(&s0, &s2);
  move(&s1, &s0);
  move(&s1, &s2);
  move(&s0, &s2);

  printf("\nYENİ:\n");
  print_hanoi_towers(s0, s1, s2);


}

int main(){
 hanoi();
 return 0;
}