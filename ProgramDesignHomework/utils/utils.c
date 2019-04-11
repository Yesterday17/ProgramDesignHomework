#include "utils.h"
#include <stdlib.h>

/**
 * 随机数
 * @param min 最小值
 * @param max 最大值
 * @return
 */
int Rand(int min, int max) {
  float x = rand();
  return (int) (rand() % (max - min) + min);
}