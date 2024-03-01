#include "mytime.h"
#include "stdio.h"

#ifdef LIST
#include "StackList/stack_list.h"
#else
#include "StackArr/stack_arr.h"
#endif

void test3(struct Stack* stack_copy) {
  for (int i = 0; i < 1000000; ++i) {
    int key = rand() % 2 + 1;
    switch (key) {
      case 1:
        push(stack_copy, &key);
        break;
      case 2:
        pop(stack_copy);
      default:
        break;
    }
  }
}

int main(int argc, char** argv) {
#ifdef LIST
  struct Stack* stack_copy = stack_ctr(sizeof(int));
#else
  struct Stack* stack_copy = stack_ctr(1, sizeof(int));
#endif
  srand(time(NULL));

  for (int i = 0; i < 1000000; ++i) {
    push(stack_copy, &i);
  }

  long long time_start = Microseconds();

  test3(stack_copy);

  printf("%lld\n", Microseconds() - time_start);

  stack_dtr(stack_copy);
}
