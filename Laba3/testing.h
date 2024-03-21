#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "stddef.h"

double Microseconds() {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (double)1e6 + currentTime.tv_usec;
}

double* test_sortings(const char* test_folder,
                      void (*sorting_function)(int*, size_t),
                      const char* result_path, int from, int to, int step) {
  int size, k, count = 0;
  double* test_times = (double*)calloc((to - from) / step, sizeof(double));

  for (size = from; size <= to; size += step) {
    int k = 0;
    while (++k) {
      char test_filename[50], answer_filename[50];
      sprintf(test_filename, "%s/%d_%d.in", test_folder, size, k);
      sprintf(answer_filename, "%s/%d_%d.out", test_folder, size, k);

      FILE* test_file = fopen(test_filename, "r");
      FILE* answer_file = fopen(answer_filename, "r");

      if (test_file == NULL || answer_file == NULL) {
        break;
      }

      int* array = (int*)calloc(size, sizeof(int));
      int* sorted_array = (int*)calloc(size, sizeof(int));

      for (int i = 0; i < size; i++) {
        fscanf(test_file, "%d", &array[i]);
        fscanf(answer_file, "%d", &sorted_array[i]);
      }

      clock_t start = Microseconds();
      sorting_function(array, size);
      clock_t end = Microseconds();

      test_times[count] += end - start;

      for (int i = 0; i < size; ++i) {
        assert(array[i] == sorted_array[i]);
      }

      fclose(test_file);
      fclose(answer_file);

      free(array);
      free(sorted_array);
    }
    test_times[count] /= k;
    ++count;
  }

  FILE* result_file = fopen(result_path, "w");
  if (result_file != NULL) {
    for (int i = 0; i < count; i++) {
      fprintf(result_file, "Test %d: %.6f seconds\n", i + 1, test_times[i]);
    }
    fclose(result_file);
  }

  return test_times;
}
