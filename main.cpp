#define LINKED_LIST
#ifdef LINKED_LIST
#include <iostream>
using namespace std;

/**
  {} = Node;
  [] = referência de memória;
  head = primeiro endereço, ele nos dá acesso à lista toda;
  [204, 217, 232, 252];
  {6, 217} -> {5, 232} -> {2, 252} -> {3, nullptr};

  time complexity: O(n); space: 0(1);
  Insertion: ;
*/
struct Node {
  int data;
  Node *next;
};

int main() {
  Node first{6};
  Node second{5};
  Node third{2};
  Node forth{3, nullptr};

  first.next = &second;
  second.next = &third;
  third.next = &forth;

  Node *head = &first;

  std::cout << "Iteration over Linked List" << endl;
  for (Node *node = head; node != nullptr; node = node->next) {
    cout << "Node[" << node << "] = { data: " << node->data
         << ", next: " << node->next << " }" << endl;
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
