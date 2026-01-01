#pragma once
#include <stdexcept>

inline int Factorial(const int n) {
  if (n < 0)
    throw std::invalid_argument{"number must be greater than 1"};
  int answer = 1;
  for (int i = 2; i <= n; i++)
    answer = answer * i;
  return answer;
}
