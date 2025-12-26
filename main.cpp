#define LINKED_LIST
#ifdef LINKED_LIST
#include <iostream>
using namespace std;

/**
  {} = Node;
  [] = referência de memoria;
  head = primeiro endereço, ele nos dá acesso a lista toda;
  [204, 217, 232, 252];
  { 6, 217 } -> { 5, 232 } -> { 2, 252 } -> { 3, nullptr };
*/
struct Node {
  int data;
  Node *next;
};

int main(int argc, const char **argv) {
  Node primeiro{6};
  Node segundo{5};
  Node terceiro{2};
  Node quarto{3, nullptr};

  primeiro.next = &segundo;
  segundo.next = &terceiro;
  terceiro.next = &quarto;

  const int LENGTH = 4;
  Node linkedList[LENGTH]{primeiro, segundo, terceiro, quarto};
  for (short i = 0; i < LENGTH; i++) {
    cout << "Node[" << i << "] = { data: " << linkedList[i].data << ", "
         << linkedList[i].next << " }" << endl;
  }

  return 0;
}

#endif // LINKED_LIST

// #define TEMPLATE
#ifdef TEMPLATE
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
#endif // TEMPLATE

// #define COUT_VS_PRINTF
#ifdef COUT_VS_PRINTF
#include <cstdio>
#include <iostream>
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
