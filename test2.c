#include "mytime.h"
#include "stdio.h"

#ifdef LIST
#include "StackList/stack_list.h"
#else
#include "StackArr/stack_arr.h"
#endif

void iteration_1(struct Stack* stack_copy, size_t number) {
  size_t to_push = number;

  size_t stored = number;

  while (stored >= 100000) {
    for (size_t i = 0; i < to_push / 2; ++i) {
      pop(stack_copy);
    }

    stored -= to_push / 2;

    for (size_t i = 0; i < to_push / 4; ++i) {
      push(stack_copy, &i);
    }
    stored += to_push / 4;

    to_push = stored;
  }
}

void test2(struct Stack* stack_copy) {
  size_t to_push = 1000000;
  for (int i = 0; i < to_push; ++i) {
    push(stack_copy, &i);
  }

  size_t stored = to_push;

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 10000; ++j) {
      pop(stack_copy);
    }
    for (int j = 0; j < 10000; ++j) {
      push(stack_copy, &j);
    }
  }

  iteration_1(stack_copy, 1000000);

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 10000; ++j) {
      pop(stack_copy);
    }
    for (int j = 0; j < 10000; ++j) {
      push(stack_copy, &j);
    }
  }
}

int main(int argc, char** argv) {
#ifdef LIST
  struct Stack* stack_copy = stack_ctr(sizeof(int));
#else
  struct Stack* stack_copy = stack_ctr(1, sizeof(int));
#endif

  long long time_start = Microseconds();

  test2(stack_copy);

  printf("%lld\n", Microseconds() - time_start);

  stack_dtr(stack_copy);
}
