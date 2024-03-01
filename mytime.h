#include <sys/time.h>
#include "time.h"
#include "stddef.h"


long long Microseconds() {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (long long )1e6 + currentTime.tv_usec;
}