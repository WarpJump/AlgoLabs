#include "stdio.h"
#include "time.h"

#ifdef LIST
#include "StackList/stack_list.h"
#else
#include "StackArr/stack_arr.h"
#endif

void test3(struct Stack* aboba) {
  for (int i = 0; i < 1000000; ++i) {
    push(aboba, &i);
  }
  for (int i = 0; i < 1000000; ++i) {
    int key = rand() % 2 + 1;
    switch (key) {
      case 1:
        push(aboba, &key);
        break;
      case 2:
        pop(aboba);
      default:
        break;
    }
  }
}

int main(int argc, char** argv) {
#ifdef LIST
  struct Stack* aboba = stack_ctr(sizeof(int));
#else
  struct Stack* aboba = stack_ctr(1, sizeof(int));
#endif
  srand(time(NULL));

  test3(aboba);

  stack_dtr(aboba);
}
