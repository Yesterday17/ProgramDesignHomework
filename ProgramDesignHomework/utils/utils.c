#include "utils.h"
#include <stdlib.h>
#include <time.h>

int Rand(int min, int max) {
  float x = rand();
  return (int)(rand() % (max - min) + min);
}