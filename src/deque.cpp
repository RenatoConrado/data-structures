#include <DequeLinkedList.hpp>
#include <iostream>
using namespace std;

int main() {
  DequeLinkedList<int> list;

  list.insertRear(3);
  list.insertRear(2);
  list.insertRear(5);
  list.insertRear(6);

  cout << "Iteration over " << list.size() << " elements" << endl;
  cout << list.toString() << endl;

  constexpr auto insert = 7;
  cout << "Inserting a new node: " << insert << endl;
  list.insertFront(insert);
  cout << list.toString() << endl;

  cout << "Removing a node: " << list.getFrontString();
  list.deleteFront();
  cout << "Removing a node: " << list.getFrontString();
  list.deleteFront();
  cout << endl << list.toString() << endl;

  list.clear();
  try {
    cout << "Acessando os elementos" << endl
         << "Frente: " << list.getFrontString()
         << "Atras : " << list.getRearString();
  } catch (runtime_error &error) {
    cerr << error.what() << endl;
  }

  return EXIT_SUCCESS;
}
