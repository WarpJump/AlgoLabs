#include "stdio.h"
#include "time.h"

#ifdef LIST
#include "StackList/stack_list.h"
#else
#include "StackArr/stack_arr.h"
#endif

void test4(struct Stack* aboba, size_t number) {
  for (int i = 0; i < number; ++i) {
    push(aboba, &i);
  }
}

int main(int argc, char** argv) {
#ifdef LIST
  struct Stack* aboba = stack_ctr(sizeof(int));
#else
  struct Stack* aboba = stack_ctr(1, sizeof(int));
#endif
  srand(time(NULL));

  size_t iter = strtol(argv[1], nullptr, 10);

  test4(aboba, iter);

  stack_dtr(aboba);
}
