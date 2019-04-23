#include <stdio.h>
#define MAX_STACK_SIZE 3

// DİKKAT : Bu kütüphane (stackproc) ders sırasında benim kendi yöntemimle
// yazdığım kodları içermektedir. Hocanın yazdığı kodları incelemek için
// test/stack_test.c dosyasını inceleyiniz.

int pop(int** stack){
  int value = **(stack);
  (*stack)--;
  return value;
}

void push(int** stack, int value){
  *(++(*stack)) = value;
}

int stack_index(int* stack){
  //printf("stack_index stack memory address: %p\n", stack);
  int size = 0;
  for(int i = 0; i < MAX_STACK_SIZE; i++){
    //printf("Stack values: Addres: %p - value %d\n", (stack-i), *(stack-i));
    if(*(stack-i) != 255){
      ++size;
    }else{
      return size;
    }
  }
  return size;
}

void print_stack(int* stack){
  //printf("Stack Address: %d\n", stack);
  int current_index = stack_index(stack);
  for(int i = MAX_STACK_SIZE; i > 0; i--){
    //printf("curent_index: %d\n", current_index);
    //printf("Stack Index Address: %p\n", stack-(i - current_index));
    if(i > current_index){
      printf("-\n");
    }else{
      printf("%d\n",*(stack-(current_index-i)));
    }
  }
}

void print_hanoi_towers(int* stack0, int* stack1, int* stack2){
  printf("\n");
  int current_indexs[] = {stack_index(stack0), stack_index(stack1), stack_index(stack2)};
  int* stacks[] = {stack0, stack1, stack2};
  for(int i = MAX_STACK_SIZE; i > 0; i--){
    //printf("curent_index: %d\n", current_index);
    //printf("Stack Index Address: %p\n", stack-(i - current_index));
    for(int t  = 0; t < 3; t++){
      if(i > current_indexs[t]){
        printf("|\t");
      }else{
        printf("%d\t",*(stacks[t]-(current_indexs[t]-i)));
      }
    }
    printf("\n");
  }
  for(int i = 0; i < 18;i++){printf("_");}
  printf("\n");
}

int move(int** stack1, int** stack2){
  //printf("stack1 value: %d, stack2 value: %d\n", **stack1, **stack2);
  //printf("stack2_index: %d\n", stack_index(*stack2));
  if(**stack2 < **stack1 || stack_index(*stack2) >= 3){
    printf("Not moving\n");
    return 0;
  }else{
    int val = pop(stack1);
    //printf("Value: %d\n", val);
    push(stack2, val);
    return 0;
  }
}