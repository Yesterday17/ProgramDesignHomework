#define UNIT_TEST
#include "gtest/gtest.h"

extern "C" {
#include "../../ProgramDesignHomework/utils/fs.h"
}

TEST(TestFileExist, NOT_EXIST) {
  ASSERT_FALSE(FileExist("THIS_FILE_NOT_EXIST"));
}

TEST(TestFileExist, EXIST) {
  ASSERT_TRUE(FileExist("ProgramDesignHomework.exe"));
}