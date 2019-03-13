#define UNIT_TEST
#include "gtest/gtest.h"

extern "C" {
#include "../../ProgramDesignHomework/utils/fs.c"
}

TEST(Not_Exist, TestFileExist) {
  ASSERT_FALSE(FileExist("THIS_FILE_NOT_EXIST"));
}

TEST(Exist, TestFileExist) {
  ASSERT_TRUE(FileExist("ProgramDesignHomework.exe"));
}