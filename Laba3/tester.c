#include <sys/stat.h>

#include "quadratic_sortings.h"

#define EVAL(...) EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

#define EMPTY(...)
#define DEFER(...) __VA_ARGS__ EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()

#define EVAL_LIST_OF_FUNC(...) EVAL(LIST_OF_FUNC_ADAPTER(__VA_ARGS__))

#define LIST_OF_FUNC_ADAPTER_INDERECT() LIST_OF_FUNC_ADAPTER

#define LIST_OF_FUNC_ADAPTER(func1, func2, ...)                  \
  do {                                                                      \
    __VA_OPT__(DEFER(LIST_OF_FUNC_ADAPTER_INDERECT)()(func2, __VA_ARGS__);) \
    assert(mkdir("sorting_results" "+" #func1, 777) == 0);                                                     \
    test_sortings(src, func1##_sort, #func1, from, to, step);                 \
  } while (0)

void test_quadratic() {
  int from = 1;
  int to = 150;
  int step = 1;
  char src[50] = "small_tests";
  EVAL_LIST_OF_FUNC(insertion, bubble, selection, shell);
}

int main() {
    mkdir("sorting_results", 777);
    test_quadratic();
}