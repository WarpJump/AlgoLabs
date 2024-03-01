#include "mytime.h"
#include "stdio.h"
#include "time.h"

#ifdef LIST
#include "StackList/stack_list.h"
#else
#include "StackArr/stack_arr.h"
#endif

void test4(struct Stack* stack_copy, size_t number) {
  for (int i = 0; i < number; ++i) {
    push(stack_copy, &i);
  }
}

int main(int argc, char** argv) {
#ifdef LIST
  struct Stack* stack_copy = stack_ctr(sizeof(int));
#else
  struct Stack* stack_copy = stack_ctr(1, sizeof(int));
#endif
  srand(time(NULL));

  size_t iter = strtol(argv[1], nullptr, 10);

  long long time_start = Microseconds();

  test4(stack_copy, iter);

  printf("%lld\n", Microseconds() - time_start);

  stack_dtr(stack_copy);
}
