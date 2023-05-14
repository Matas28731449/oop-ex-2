#include <gtest/gtest.h>
#include "vector/headers/references.h"

TEST(student, ValueAssignCheck) {
    student tmp;
    string  value = "test";
    tmp.setName(value);
    EXPECT_TRUE(tmp.getName() == value);
}
TEST(student, GradeCountCheck) {
    student tmp;
    int     value = 2;
    tmp.setGrade(6);
    tmp.setGrade(5);
    EXPECT_TRUE(tmp.getGrade().size() == value);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}