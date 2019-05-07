#include <stdio.h>

typedef struct HayvanStruct{
  int yas;
  char* cins;
  char* ses;
  void (*ses_cikar)(); // Fonksiyon Pointer
} hayvan;

void kedi_sesi(void){
  printf("miyav!\n");
}

void kopek_sesi(void){
  printf("hav!\n");
}

int main(void){
  hayvan kedi, kopek;
  kedi.ses_cikar  = kedi_sesi;  // Fonksiyon Pointer atandı
  kopek.ses_cikar = kopek_sesi; // Fonksiyon Pointer atandı

  kedi.ses_cikar();
  kopek.ses_cikar();

  return 0;
}