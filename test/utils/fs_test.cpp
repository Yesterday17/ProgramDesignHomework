#include "gtest/gtest.h"

extern "C" {
#include "../../ProgramDesignHomework/utils/fs.h"
}

/**
 * 测试不存在文件判断
 */
TEST(TestFileExist, NOT_EXIST) {
  ASSERT_FALSE(FileExist("THIS_FILE_NOT_EXIST"));
}

/**
 * 测试存在文件判断
 */
TEST(TestFileExist, EXIST) {
  ASSERT_TRUE(FileExist("ProgramDesignHomework.exe"));
}