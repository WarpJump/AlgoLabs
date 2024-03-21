#include "stdlib.h"

#include "testing.h"

void insertion_sort(int* array, size_t size) {
  int key;
  size_t i, j;
  for (i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

void bubble_sort(int* array, size_t size) {
  int temp;
  size_t i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void selection_sort(int* array, size_t size) {
  int temp;
  size_t min_idx;
  for (size_t i = 0; i < size - 1; i++) {
    min_idx = i;
    for (size_t j = i + 1; j < size; j++) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }
    temp = array[min_idx];
    array[min_idx] = array[i];
    array[i] = temp;
  }
}

void shell_sort(int* array, size_t size) {
  int temp;
  size_t step, i, j;
  for (step = 1; step < size / 3; step = 3 * step + 1) {
  }

  for (; step > 0; step /= 3) {
    for (i = step; i < size; i += step) {
      temp = array[i];
      for (j = i; j >= step && array[j - step] > temp; j -= step) {
        array[j] = array[j - step];
      }
      array[j] = temp;
    }
  }
}