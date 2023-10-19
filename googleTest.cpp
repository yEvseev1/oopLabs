#include <gtest/gtest.h>
#include "func.cpp"

TEST(testFunc, test1) {
    ASSERT_TRUE(func(1,2) == 1);
}

TEST(testFunc, test2) {
    ASSERT_TRUE(func(1,77) == 76);
}

TEST(testFunc, test3) {
    ASSERT_TRUE(func(-5,2) == 0);
}

TEST(testFunc, test4) {
    ASSERT_TRUE(func(-6,-7) == 0);
}  

TEST(testFunc, test5) {
    ASSERT_TRUE(func(0,0) == 0);
}

TEST(testFunc, test6) {
    ASSERT_TRUE(func(10,25) == 249);
}

TEST(testFunc, test7) {
    ASSERT_TRUE(func(65,65) == 4224);
}

TEST(testFunc, test8) {
    ASSERT_TRUE(func(0,2) == 0);
}  
TEST(testFunc, test9) {
    ASSERT_TRUE(func(1,1) == 0);
}  




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}