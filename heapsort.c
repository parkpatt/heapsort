#include <stdio.h>
#include <stdlib.h>

#include "printArray.h"

#define LEFT(i) (i << 1);
#define RIGHT(i) ((i << 1) + 1);

int Swap(int* arr, int len, int idx1, int idx2){
  if (idx1 >= len || idx2 >= len) return 0;
  int tmp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = tmp;
  return 1;
}

void MinHeapify(int* arr, int len, int i){
  int l = LEFT(i);
  int r = RIGHT(i);
  int smallest = i;
  if (l < len && arr[l] < arr[i]){
    smallest = l;
  }
  if (r < len && arr[r] < arr[smallest]){
    smallest = r;
  }
  if (smallest != i){
    Swap(arr, len, i, smallest);
    MinHeapify(arr, len, smallest);
  }
  return;
}

void MaxHeapify(int* arr, int len, int i){
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest = i;
  if (l < len && arr[l] > arr[i]){
    largest = l;
  }
  if (r < len && arr[r] > arr[largest]){
    largest = r;
  }
  if (largest != i){
    Swap(arr, len, i, largest);
    MaxHeapify(arr, len, largest);
  }
  return;
}

void BuildMaxHeap(int* arr, int len){
  for (int i = len / 2; i >= 0; i--){
    MaxHeapify(arr, len, i);
  }
  return;
}

void BuildMinHeap(int* arr, int len){
  for (int i = len / 2; i >=0; i--){
    MinHeapify(arr, len, i);
  }
  return;
}

void MaxHeapSort(int* arr, int len){
  BuildMaxHeap(arr, len);
  for (int i = len; i > 0; i--){
    Swap(arr, len, 0, i);
    len--;
    MaxHeapify(arr, len, 0);
  }
  return;
}

void MinHeapSort(int* arr, int len){
  BuildMinHeap(arr, len);
  for (int i = len; i > 0; i--){
    Swap(arr, len, 0, i);
    len--;
    MinHeapify(arr, len, 0);
  }
  return;
}

int main(){
  printf("===MAXHEAP===\n");
  int test0[5] = {3, 8, 2, 10, 15};
  printf("unsorted: ");
  PrintIntArray(test0, 5);
  MaxHeapSort(test0, 5);
  printf("sorted: ");
  PrintIntArray(test0, 5);
  printf("===MINHEAP===\n");
  int test1[5] = {18, 2, 9, 12, 4};
  printf("unsorted: ");
  PrintIntArray(test1, 5);
  MinHeapSort(test1, 5);
  printf("sorted: ");
  PrintIntArray(test1, 5);
  return 0;
}
