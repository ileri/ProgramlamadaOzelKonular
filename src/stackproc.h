// DİKKAT : Bu kütüphane (stackproc) ders sırasında benim kendi yöntemimle
// yazdığım kodları içermektedir. Hocanın yazdığı kodları incelemek için
// test/stack_test.c dosyasını inceleyiniz.

int pop(int** stack);
void push(int** stack, int value);
void move(int** stack1, int** stack2);
int stackIndex(int* stack);
void print_stack(int* stack);
void print_hanoi_towers(int* stack0, int* stack1, int* stack2);