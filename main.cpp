#include <cstdio>
#include <iostream>
#include <ostream>

int main() {
  short i;
  const char *arrAlgo[4]{"algo1", "algo2"};
  const short length = sizeof(arrAlgo) / sizeof(arrAlgo[0]);
  arrAlgo[3] = "outra coisa";

  for (i = 0; i < length; i++)
    if (arrAlgo[i])
      std::cout << "cout  Array: [" << i << "] = " << arrAlgo[i] << std::endl;

  for (i = 0; i < length; i++)
    if (arrAlgo[i])
      printf("prinf Array: [%d] = %s\n", i, arrAlgo[i]);

  return 0;
}
