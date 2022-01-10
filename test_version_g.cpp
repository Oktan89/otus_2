#include "lib.h"
#include <gtest/gtest.h>

TEST(test_version_google, testValidVersion) {

  EXPECT_GT(version(), 0);
}
