#include <stdlib.h>
#include <stdio.h>

#include "./printArray.h"

void PrintIntArray(int* input, int size){
  for (int i = 0; i < size; i++){
    printf("%d ", input[i]);
  }
  printf("\n");
  return;
}
