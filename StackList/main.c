#include "stack_list.h"
#include "stdio.h"

int main(int argc, char** argv) {
  struct Stack* aboba = stack_ctr(sizeof(int));
  for (int i = 0; i < 10000; ++i) {
    push(aboba, &i);
  }
  for (int i = 0; i < 10000; ++i) {
    int val;
    top(aboba, &val);
    printf("%d\n", val);
    pop(aboba);
  }
  stack_dtr(aboba);
}
