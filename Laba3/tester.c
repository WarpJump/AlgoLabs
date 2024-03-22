#include "quadratic_sortings.h"

#define EVAL(...) EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) __VA_ARGS__
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

#define EMPTY(...)
#define DEFER(...) __VA_ARGS__ EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()

#define EVAL_LIST_OF_FUNC(...) EVAL(LIST_OF_FUNC_ADAPTER(__VA_ARGS__))

#define LIST_OF_FUNC_ADAPTER_INDERECT() LIST_OF_FUNC_ADAPTER

#define LIST_OF_FUNC_ADAPTER(func1, ...)                                      \
  do {                                                                        \
    /*Creating folder for current kind of sort*/                              \
    char result_dir[60];                                                      \
    sprintf(result_dir, "sorting_results/" #func1);                           \
    mkdir(result_dir, 0755);                                                   \
    fputs(RedText("Running benchmark for " #func1) "\n", stderr);             \
    double* time = test_sortings(src, func1##_sort,                           \
                                 "sorting_results/" #func1 "/" #func1 ".txt", \
                                 from, to, step);                             \
    fprintf(stderr, RedText("Now writing time: %s/time1.txt"), result_dir);  \
    FILE* time_file = fopen("sorting_results/" #func1 "/time1.txt", "w+");    \
    assert(time_file);                                                        \
    fflush(stdout);                                                           \
    for (int i = 0; i < (to - from) / step + 1; ++i) {                                  \
      fprintf(time_file, "%d %.6lf\n", i, time[i]);                                     \
    }                                                                         \
    fclose(time_file);                                                        \
    free(time);                                                               \
    __VA_OPT__(DEFER(LIST_OF_FUNC_ADAPTER_INDERECT)()(__VA_ARGS__);)          \
  } while (0)

void test_quadratic() {
  int from = 0;
  int to = 1000;
  int step = 50;
  char src[50] = "tests/small_tests";
  EVAL_LIST_OF_FUNC(insertion, bubble, selection, shell);
}

int main() {
  mkdir("sorting_results", 0755);
  test_quadratic();
}