#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/random.h>



int main(int argc, char *argv[]) {

  unsigned int seed;
  getrandom(&seed, sizeof(unsigned int), 0);

  srandom(seed);

  if (argc != 3) {
    printf("Usage: %s <number_of_elements> <max_element_value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int max_val = atoi(argv[2]);
  //fprintf(stderr, "%d\n", max_val);

  for (int i = 0; i < n; i++) {
    printf("%d ", random() % (max_val + 1));
  }

  return 0;
}