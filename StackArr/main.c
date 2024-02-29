#include "stack_arr.h"
#include "stdio.h"

int main(int argc, char** argv) {
  struct Stack* aboba = stack_ctr(10, sizeof(int));
  for (int i = 0; i < 100; ++i) {
    push(aboba, &i);
  }
  for (int i = 0; i < 100; ++i) {
    int val;
    top(aboba, &val);
    printf("%d\n", val);
    pop(aboba);
  }
  stack_dtr(aboba);
}
