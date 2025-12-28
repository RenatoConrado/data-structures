#define LINKED_LIST
#ifdef LINKED_LIST
#include <iostream>
#include <string>
using namespace std;

/*
{} = Node;
[] = referência de memória;
[204, 217, 232, 252];
{6, 217} -> {5, 232} -> {2, 252} -> {3, nullptr}; */
template <typename T> struct Node {
  T data;
  Node *next = nullptr;
};

/* Primeiro elemento, ele nos dá acesso à lista toda */
Node<int> *head = nullptr;

/* Iteration: time complexity: O(n), space: O(1) */
template <typename T> void iterate() {
  for (Node<T> *node = head; node != nullptr; node = node->next)
    cout << "Node[" << node << "] = {data: " << node->data
         << ", next: " << node->next << "}" << endl;
}

/*
Insertion: time complexity: O(1) por que temos a referencia do elemento;
[1: 204, 2: 217, 3: **264**, 4: 232, 5: 252];
{6, 217} -> {5, 264} -> **{8, 232}** -> {2, 252} -> {3, nullptr}; */
template <typename T> void insertAfter(Node<T> *afterNode, Node<T> *newNode) {
  newNode->next = afterNode->next;
  afterNode->next = newNode;
}

/*
[1: **278**, 2: 204, 3: 217, 4: 264, 5: 232, 6: 252];
**{10, 204}** -> {6, 217} -> {5, 264} -> {8, 232} -> {2, 252} -> {3, nullptr};*/
template <typename T> void insertFirst(Node<T> *newNode) {
  newNode->next = head;
  head = newNode;
}

/*
exclusion: time complexity: entre O(1) primeiro node, até O(n) ultimo node;
por que temos que atravessar a estrutura até achar o elemento; */
template <typename T> void remove(Node<T> *node) {
  if (head == node) {
    head = node->next;
    return delete node;
  }

  for (Node<T> *index = head; index != nullptr; index = index->next)
    if (index->next == node) {
      index->next = node->next;
      return delete node;
    }
}

template <typename T> Node<T> *findByIndex(int index) {
  short i = 0;
  for (Node<T> *node = head; node != nullptr; node = node->next, i++)
    if (i == index)
      return node;
  return nullptr;
}

template <typename T> Node<T> *findByValue(T value) {
  for (Node<T> *node = head; node != nullptr; node = node->next)
    if (node->data == value)
      return node;
  return nullptr;
}

int main() {
  Node<int> *first = new Node{6};
  Node<int> *second = new Node{5};
  Node<int> *third = new Node{2};
  Node<int> *forth = new Node<int>{3, nullptr};

  first->next = second; // first->next é um atalho para (*first).next
  second->next = third;
  third->next = forth;

  head = first;

  cout << "Iteration over Linked List" << endl;
  iterate<int>();

  Node<int> *toInsert1 = new Node{8};
  Node<int> *toInsert2 = new Node{10};
  cout << endl
       << "Inserting a new node: [" << toInsert1 << "]" << endl
       << "Inserting a new node: [" << toInsert2 << "]" << endl;
  insertAfter(second, toInsert1);
  insertFirst(toInsert2);
  iterate<int>();

  Node<int> *toRemove1 = head;
  Node<int> *toRemove2 = forth;
  cout << endl
       << "Removing a node: [" << toRemove1 << "]" << endl
       << "Removing a node: [" << toRemove2 << "]" << endl;
  remove(toRemove1);
  remove(toRemove2);
  iterate<int>();

  cout << endl
       << "Head mudou e node foi deletado da memoria" << endl
       << "Head {" << head->data << ", " << head->next << "}" << endl
       << "Del1 {" << toRemove1->data << ", " << toRemove1->next << "}" << endl
       << "Del2 {" << toRemove2->data << ", " << toRemove2->next << "}" << endl;

  constexpr int index = 2;
  constexpr int value = 2;
  const Node<int> *found1 = findByIndex<int>(index);
  const Node<int> *found2 = findByValue(value);

  cout << endl
       << "Acesando os elementos i: " << index << ", value: " << value << endl
       << found1 << " {" << found1->data << ", " << found1->next << "}" << endl
       << found2 << " {" << found2->data << ", " << found2->next << "}" << endl;

  return 0;
}
#endif // LINKED_LIST
