//
// Created by focus on 24.03.2021.
//

#include "gtest/gtest.h"
#include "someLib.h"

TEST(CoreTest, ExampleTest1) {
    ASSERT_TRUE(true);
}

TEST(CoreTest, ExampleTest2) {
    const auto expected = "Simple message from someLibDir";
    const auto actual = someLib::getMessage();
    EXPECT_STREQ(actual.c_str(), expected);
}
