#include <gtest/gtest.h>

#include "Six.hpp"

using namespace std;

TEST(constructor, constructorWithoutArgs) {
    Six object1;

    ASSERT_EQ(object1.getSize(), 0);

    ASSERT_THROW(object1.getNumber(), domain_error);
}

TEST(constructor, constructorWithString) {
    Six object1("123450");

    ASSERT_THROW(Six object12("678"), invalid_argument);
    ASSERT_EQ(object1.getSize(), 6);
    ASSERT_EQ(object1.getNumber(), "123450");
}

TEST(constructor, constructorWithInitList) {
    Six object1{'1', '2', '3', '4', '5', '0'};

    ASSERT_THROW(Six object2{'6'}, invalid_argument);

    ASSERT_EQ(object1.getSize(), 6);
    ASSERT_EQ(object1.getNumber(), "123450");
}

TEST(constructor, copy) {
    Six object1;
    Six object2("12345");
    Six object3(object2);

    ASSERT_EQ(object2.getNumber(), object3.getNumber());
    ASSERT_EQ(object2.getSize(), object3.getSize());

    ASSERT_THROW(Six object4(object1), domain_error);
}

TEST(constructor, move) {
    Six object1("123450");
    Six object2(move(object1));

    ASSERT_EQ(object2.getNumber(), "123450");
    ASSERT_EQ(object2.getSize(), 6);

    ASSERT_EQ(object1.getSize(), 0);

    ASSERT_THROW(object1.getNumber(), domain_error);
}

TEST(assignment, copy) {
    Six object1;
    Six object2("12345");
    Six object3;

    object3 = object2;

    ASSERT_EQ(object2.getNumber(), object3.getNumber());

    ASSERT_THROW(object3 = object1, domain_error);
}

TEST(assignment, move) {
    Six object1("12345");
    Six object2;
    object2 = move(object1);

    ASSERT_EQ(object2.getNumber(), "12345");
    ASSERT_EQ(object2.getSize(), 5);

    ASSERT_EQ(object1.getSize(), 0);

    ASSERT_THROW(object1.getNumber(), domain_error);
}

TEST(methods, getSize) {
    Six object1;
    Six object2("123");

    ASSERT_EQ(object1.getSize(), 0);
    ASSERT_EQ(object2.getSize(), 3);
}

TEST(methods, getNumber) {
    Six object1;
    Six object2("123");

    ASSERT_THROW(object1.getNumber(), domain_error);

    ASSERT_EQ(object2.getSize(), 3);
}

TEST(output, output) {
    Six object1;

    ASSERT_THROW(cout << object1, domain_error);
}

TEST(comparisonOperators, equal) {
    Six object1;
    Six object2("1234");
    Six object3("1234");
    Six object4("12345");

    ASSERT_TRUE(object2 == object3);
    ASSERT_TRUE(object3 == object2);

    ASSERT_FALSE(object2 == object4);
    ASSERT_FALSE(object4 == object2);

    ASSERT_THROW(object1 == object4, domain_error);
    ASSERT_THROW(object4 == object1, domain_error);
}

TEST(comparisonOperators, noEqual) {
    Six object1;
    Six object2("1234");
    Six object3("1234");
    Six object4("12345");

    ASSERT_TRUE(object2 != object4);
    ASSERT_TRUE(object4 != object2);

    ASSERT_FALSE(object2 != object3);
    ASSERT_FALSE(object3 != object2);

    ASSERT_THROW(object1 != object3, domain_error);
    ASSERT_THROW(object3 != object1, domain_error);
}

TEST(comparisonOperators, more) {
    Six object1;
    Six object2("1234");
    Six object3("1234");
    Six object4("12345");

    ASSERT_TRUE(object4 > object2);

    ASSERT_FALSE(object2 > object3);
    ASSERT_FALSE(object3 > object2);
    ASSERT_FALSE(object3 > object4);

    ASSERT_THROW(object1 > object3, domain_error);
    ASSERT_THROW(object3 > object1, domain_error);
}

TEST(comparisonOperators, Less) {
    Six object1;
    Six object2("1234");
    Six object3("1234");
    Six object4("12345");

    ASSERT_TRUE(object2 < object4);

    ASSERT_FALSE(object2 < object3);
    ASSERT_FALSE(object3 < object2);
    ASSERT_FALSE(object4 < object2);

    ASSERT_THROW(object1 < object3, domain_error);
    ASSERT_THROW(object3 < object1, domain_error);
}

TEST(comparisonOperators, lessOrEqual) {
    Six object1;
    Six object2("1234");
    Six object3("1234");
    Six object4("12345");

    ASSERT_TRUE(object4 <= object4);
    ASSERT_TRUE(object2 <= object3);
    ASSERT_TRUE(object3 <= object2);

    ASSERT_FALSE(object4 <= object2);

    ASSERT_THROW(object1 <= object3, domain_error);
    ASSERT_THROW(object3 <= object1, domain_error);
}

TEST(comparisonOperators, moreOrEqual) {
    Six object1;
    Six object2("1234");
    Six object3("1234");
    Six object4("12345");

    ASSERT_TRUE(object4 >= object4);
    ASSERT_TRUE(object2 >= object3);
    ASSERT_TRUE(object3 >= object2);

    ASSERT_FALSE(object2 >= object4);

    ASSERT_THROW(object1 >= object3, domain_error);
    ASSERT_THROW(object3 >= object1, domain_error);
}

TEST(arithmeticOpperators, addition) {
    Six object1;
    Six object2("125431300");
    Six object3("241512223");
    Six object4("0");

    ASSERT_EQ((object2 + object3).getNumber(), "411343523");
    ASSERT_EQ((object3 + object2).getNumber(), "411343523");

    ASSERT_EQ((object2 + object4).getNumber(), "125431300");
    ASSERT_EQ((object4 + object2).getNumber(), "125431300");

    ASSERT_THROW(object1 + object3, domain_error);
    ASSERT_THROW(object3 + object1, domain_error);
}

TEST(arithmeticOpperators, substraction) {
    Six object1;
    Six object2("1254313003");
    Six object3("241512223");
    Six object4("0");

    ASSERT_EQ((object2 - object3).getNumber(), "1012400340");
    ASSERT_EQ((object2 - object4).getNumber(), "1254313003");

    ASSERT_THROW((object3 - object2).getNumber(), logic_error);

    ASSERT_THROW(object1 - object3, domain_error);
    ASSERT_THROW(object3 - object1, domain_error);
}

TEST(arithmeticOperationsWithAssignment, addition) {
    Six object1;
    Six object2("1254313003");
    Six object3("241512223");
    Six object4("0");

    ASSERT_EQ((object3 += object2).getNumber(), "1540225230");

    ASSERT_EQ((object2 += object4).getNumber(), "1254313003");
    ASSERT_EQ((object4 += object2).getNumber(), "1254313003");

    ASSERT_THROW(object1 += object3, domain_error);
    ASSERT_THROW(object3 += object1, domain_error);
}

TEST(arithmeticOperationsWithAssignment, substraction) {
    Six object1;
    Six object2("1254313003");
    Six object3("241512223");
    Six object4("0");

    ASSERT_EQ((object2 -= object3).getNumber(), "1012400340");
    ASSERT_EQ((object3 -= object3).getNumber(), "0");

    ASSERT_THROW((object4 -= object2).getNumber(), logic_error);

    ASSERT_THROW(object1 -= object3, domain_error);
    ASSERT_THROW(object3 -= object1, domain_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}