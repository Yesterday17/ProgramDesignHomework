#include "gtest/gtest.h"

extern "C" {
#include "../../ProgramDesignHomework/utils/utils.h"
}

/**
 * ²âÊÔËæ»úÊý
 */

TEST(TestUtils, RandomPositive) {
  int rnd = Rand(1, 100);
  EXPECT_LT(rnd, 101);
  EXPECT_GT(rnd, 0);
}

TEST(TestUtils, RandomNagative) {
  int rnd = Rand(-100, -1);
  EXPECT_LT(rnd, 0);
  EXPECT_GT(rnd, -101);
}

TEST(TestUtils, RandomMixed) {
  int rnd = Rand(-100, 100);
  EXPECT_LT(rnd, 101);
  EXPECT_GT(rnd, -101);
}