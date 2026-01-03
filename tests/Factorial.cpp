#include <gtest/gtest.h>

#include <Factorial.hpp>

// Tests factorial of 0.
TEST(factorial, HandlesZeroInput) { EXPECT_EQ(Factorial(0), 1); }

// Tests factorial of positive numbers.
TEST(factorial, HandlesPositiveInput) {
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(8), 40320);
}

// Tests factorial of negative numbers.
TEST(factorial, HandlesNegativeInput) {
  EXPECT_THROW(Factorial(-1), std::invalid_argument);
  EXPECT_THROW(Factorial(-2), std::invalid_argument);
  EXPECT_THROW(Factorial(-3), std::invalid_argument);
  EXPECT_THROW(Factorial(-8), std::invalid_argument);
}
