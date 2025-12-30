#include <DoubleLinkedList.hpp>
#include <iostream>
using namespace std;

// #define REVERSE_LINKED_LIST
#ifdef REVERSE_LINKED_LIST
int main() {
  DoubleLinkedList<int> list;
  list.insertLast(2);
  list.insertLast(4);
  list.insertLast(6);
  list.insertLast(5);
  list.clearPrevious();
  cout << "Initial Values: " << endl;
  list.coutAll();

  cout << "They should look like this in reverse: " << endl;
  DoubleLinkedList<int>::printReverse(list.getHead());

  cout << endl << "Reversed List: " << endl;
  list.reverse();
  list.coutAll();

  cout << "Reversed List using recursion: " << endl;
  list.reverseUsingRecursion(list.getHead());
  list.coutAll();

  return EXIT_SUCCESS;
}
#endif // REVERSE_LINKED_LIST

#define USUAL_TEST
#ifdef USUAL_TEST
int main() {
  DoubleLinkedList<int> list;

  list.insertLast(3);
  list.insertLast(2);
  list.insertLast(5);
  list.insertLast(6);

  cout << "Iteration over " << list.getLength() << " elements" << endl;
  list.coutAll();

  constexpr short beforeSecond = 8;
  const auto second = list.getHead()->next;
  cout << "Inserting a new node: " << beforeSecond << endl
       << "before node[" << second << "]" << endl;
  list.insertBefore(second, beforeSecond);
  list.coutAll();

  const auto toRemove1 = list.findByIndex(2);
  const auto toRemove2 = list.getTail();
  if (toRemove1 == toRemove2)
    return EXIT_FAILURE;
  cout << "Removing a node: [" << toRemove1 << "]" << endl
       << "Removing a node: [" << toRemove2 << "]" << endl;
  list.remove(toRemove1);
  list.remove(toRemove2);
  list.coutAll();

  constexpr int index = 1;
  constexpr int value = 5;
  const auto found1 = list.findByIndex(index);
  const auto found2 = list.findByValue(value);
  cout << "Acessando os elementos por: index: " << index << ", value: " << value
       << endl;
  DoubleLinkedList<int>::coutNode(found1);
  DoubleLinkedList<int>::coutNode(found2);

  return EXIT_SUCCESS;
}
#endif // USUAL_TEST
