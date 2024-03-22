#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>

#include "stddef.h"

#define RedText(text) "\033[0;31m" text "\033[0m"

/*!
  \brief Macros that paints text in branches in orange
*/
#define YellowText(text) "\033[93m" text "\033[0m"

/*!
  \brief Macros that paints text in branches in magenta
*/
#define MagentaText(text) "\033[0;35m" text "\033[0m"

/*!
  \brief Macros that paints text in branches in blue
*/
#define BlueText(text) "\033[0;34m" text "\033[0m"

/*!
  \brief Macros that paints text in branches in green
*/
#define GreenText(text) "\033[0;32m" text "\033[0m"

double Microseconds() {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (double)1e6 + currentTime.tv_usec;
}

double* test_sortings(const char* test_folder,
                      void (*sorting_function)(int*, size_t),
                      const char* result_path, int from, int to, int step) {
  int size, count = 0;
  double* test_times = (double*)calloc((to - from) / step + 1, sizeof(double));

  printf("Running TEST_SORTINGS for package of tests %s, %d %d %d\n",
         test_folder, from, to, step);
  for (size = from; size <= to; size += step) {
    int k = -1;
    while (1) {
      ++k;
      char name_testfile[60], name_answerfile[60];
      sprintf(name_testfile, "%s/%d_%d.in", test_folder, size, k);
      sprintf(name_answerfile, "%s/%d_%d.out", test_folder, size, k);

      FILE* test_file = fopen(name_testfile, "r");
      fprintf(stderr, "Opening test file %s: ", name_testfile);

      if (test_file == NULL) {
        fprintf(stderr, "File does not exist\n");
        break;
      } else {
        fprintf(stderr, "Ok!\n");
      }

      FILE* answer_file = fopen(name_answerfile, "r");
      assert(answer_file);

      int* array = (int*)calloc(size, sizeof(int));
      int* sorted_array = (int*)calloc(size, sizeof(int));

      for (int i = 0; i < size; i++) {
        fscanf(test_file, "%d", &array[i]);
        fscanf(answer_file, "%d", &sorted_array[i]);
      }

      clock_t start = Microseconds();
      sorting_function(array, size);
      clock_t end = Microseconds();
      fprintf(stderr, "Test time is %ld microsec\n", end - start);

      test_times[count] += (double)(end - start);

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

  fprintf(stderr, GreenText("Writing time to file: %s\n"), result_path);
  FILE* result_file = fopen(result_path, "w+");
  if (result_file == NULL) {
    fprintf(stderr, MagentaText("Failed to create file in %s because %s\n"),
            result_path, strerror(errno));
    free(test_times);
    return NULL;
  }

  for (int i = 0; i < count; i++) {
    fprintf(stderr, "%d ", i);
    fprintf(result_file, "Test %d: %.6lf microsec\n", i + 1, test_times[i]);
  }
  fputc('\n', stderr);
  fclose(result_file);

  return test_times;
}
