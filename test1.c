#include "stdio.h"

#ifdef LIST
#include "StackList/stack_list.h"
#else
#include "StackArr/stack_arr.h"
#endif

void iteration_1(struct Stack* aboba, size_t number) {
  size_t to_push = number;
  
  size_t stored = number;

  while (stored >= 100000) {
    for (size_t i = 0; i < to_push / 2; ++i) {
      pop(aboba);
    }

    stored -= to_push / 2;

    for (size_t i = 0; i < to_push / 4; ++i) {
      push(aboba, &i);
    }
    stored += to_push / 4;

    to_push = stored;
  }
}

void test1(struct Stack* aboba) {
  for (int i = 0; i < 1000000; ++i) {
    push(aboba, &i);
  }
  iteration_1(aboba, 1000000);
}

int main(int argc, char** argv) {
#ifdef LIST
  struct Stack* aboba = stack_ctr(sizeof(int));
#else
  struct Stack* aboba = stack_ctr(1, sizeof(int));
#endif

  test1(aboba);

  stack_dtr(aboba);
}
