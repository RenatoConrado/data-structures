#include <iostream>
#include <string>

using namespace std;

template <typename T> class Array {
private:
  short length;
  T *array;

public:
  Array(short length) : length(length), array(new T[length]) {}
  ~Array() { delete[] array; }

  void fill(T value) {
    for (short i = 0; i < length; i++)
      array[i] = value;
  }

  T &at(int index) { return array[index]; }
};

int main(int argc, const char **argv) {
  Array<string> stringArray(10);
  stringArray.fill("algo");
  cout << "array[0] = " << stringArray.at(0) << endl;
  return 0;
}

#ifdef COUT_VS_PRINTF
#include <cstdio>
int main() {
  short i;
  const char *arrAlgo[4]{"algo1", "algo2"};

  const short length = sizeof(arrAlgo) / sizeof(arrAlgo[0]);
  arrAlgo[3] = "outra coisa";

  for (i = 0; i < length; i++)
    if (arrAlgo[i])
      cout << "cout  Array: [" << i << "] = " << arrAlgo[i] << endl;

  for (i = 0; i < length; i++)
    if (arrAlgo[i])
      printf("prinf Array: [%d] = %s\n", i, arrAlgo[i]);
  return 0;
}
#endif // COUT_VS_PRINTF
