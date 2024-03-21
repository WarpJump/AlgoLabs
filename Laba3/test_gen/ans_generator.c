#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  int *arr = calloc(10000000, sizeof(int));
  int n = 0;

  while (scanf("%d", &arr[n]) != EOF) {
    ++n;
  }

  qsort(arr, n, sizeof(int), cmp);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;

  free(arr);
}