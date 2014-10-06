#include "gtest/gtest.h"
#include "Globals.hpp"

TEST(GlobalsTest, getRandomIntTest) {
	EXPECT_EQ(get_random_int(0, 0), 0);
	int x = get_random_int(0, 2);
	EXPECT_TRUE(0 <= x && x < 2);
}

TEST(GlobalsTest, getRandomDoubleTest) {
	double x = get_random_double(0.0, 1.0);
	EXPECT_TRUE(0.0 <= x && x <= 1.0);
}

TEST(GlobalsTest, isZeroTest) {
	EXPECT_TRUE(is_zero(1e-40));
}

TEST(GlobalsTest, solveQuadricTest) {
	double c[3] = {6, -5, 1};
	double s[2];
	EXPECT_EQ(solve_quadric(c,s), 2);
	EXPECT_TRUE(s[0] == 2 || s[0] == 3);
	EXPECT_TRUE(s[1] == 2 || s[1] == 3);
}
