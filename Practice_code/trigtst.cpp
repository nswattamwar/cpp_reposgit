#include "triangle.cpp" // Include the implementation file
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Test for equilateral triangles
TEST(TriangleTest, Equilateral) {
    Triangle t(3.0, 3.0, 3.0);
    EXPECT_TRUE(t.isEquilateral());
    EXPECT_FALSE(t.isIsosceles()); // Equilateral is also isosceles, but this test assumes strict behavior
    EXPECT_FALSE(t.isScalene());
}

// Test for isosceles triangles
TEST(TriangleTest, Isosceles) {
    Triangle t(3.0, 4.0, 4.0);
    EXPECT_FALSE(t.isEquilateral());
    EXPECT_TRUE(t.isIsosceles());
    EXPECT_FALSE(t.isScalene());
}

// Test for scalene triangles
TEST(TriangleTest, Scalene) {
    Triangle t(3.0, 4.0, 5.0);
    EXPECT_FALSE(t.isEquilateral());
    EXPECT_FALSE(t.isIsosceles());
    EXPECT_TRUE(t.isScalene());
}

// Test for invalid triangle (e.g., zero or negative sides)
TEST(TriangleTest, InvalidTriangle) {
    Triangle t(0.0, 4.0, 5.0);
    EXPECT_FALSE(t.isEquilateral());
    EXPECT_FALSE(t.isIsosceles());
    EXPECT_FALSE(t.isScalene());
}

// Test for displayType function
TEST(TriangleTest, DisplayType) {
    Triangle t1(3.0, 3.0, 3.0);
    testing::internal::CaptureStdout();
    t1.displayType();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The triangle is equilateral.\n");

    Triangle t2(3.0, 4.0, 4.0);
    testing::internal::CaptureStdout();
    t2.displayType();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The triangle is isosceles.\n");

    Triangle t3(3.0, 4.0, 5.0);
    testing::internal::CaptureStdout();
    t3.displayType();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The triangle is scalene.\n");
}

