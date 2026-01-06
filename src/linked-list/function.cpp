#include <iostream>
using namespace std;

/*
{} = Node;
[] = referência de memória;
[204, 217, 232, 252];
{6, 217} -> {5, 232} -> {2, 252} -> {3, nullptr}; */
template <typename T> struct BynaryNode {
  T data;
  BynaryNode *next = nullptr;
};

/* Primeiro elemento, ele nos dá acesso à lista toda */
BynaryNode<int> *head = nullptr;

/* Iteration: time complexity: O(n), space: O(1) */
template <typename T> void coutAll() {
  for (BynaryNode<T> *node = head; node != nullptr; node = node->next)
    cout << "Node[" << node << "] = {data: " << node->data
         << ", next: " << node->next << "}" << endl;
}

/*
Insertion: time complexity: O(1) por que temos a referencia do elemento;
[1: 204, 2: 217, 3: **264**, 4: 232, 5: 252];
{6, 217} -> {5, 264} -> **{8, 232}** -> {2, 252} -> {3, nullptr}; */
template <typename T>
void insertAfter(BynaryNode<T> *afterNode, BynaryNode<T> *newNode) {
  newNode->next = afterNode->next;
  afterNode->next = newNode;
}

/*
[1: **278**, 2: 204, 3: 217, 4: 264, 5: 232, 6: 252];
**{10, 204}** -> {6, 217} -> {5, 264} -> {8, 232} -> {2, 252} -> {3, nullptr};*/
template <typename T> void insertFirst(BynaryNode<T> *newNode) {
  newNode->next = head;
  head = newNode;
}

/*
exclusion: time complexity: entre O(1) primeiro node, até O(n) ultimo node;
por que temos que atravessar a estrutura até achar o elemento; */
template <typename T> void remove(BynaryNode<T> *node) {
  if (head == node) {
    head = node->next;
    return delete node;
  }

  for (BynaryNode<T> *index = head; index != nullptr; index = index->next)
    if (index->next == node) {
      index->next = node->next;
      return delete node;
    }
}

/* searching: O(n) */
template <typename T> BynaryNode<T> *findByIndex(int index) {
  short i = 0;
  for (BynaryNode<T> *node = head; node != nullptr; node = node->next, i++)
    if (i == index)
      return node;
  return nullptr;
}

template <typename T> BynaryNode<T> *findByValue(T value) {
  for (BynaryNode<T> *node = head; node != nullptr; node = node->next)
    if (node->data == value)
      return node;
  return nullptr;
}

int main() {
  BynaryNode<int> *first = new BynaryNode{6};
  BynaryNode<int> *second = new BynaryNode{5};
  BynaryNode<int> *third = new BynaryNode{2};
  BynaryNode<int> *forth = new BynaryNode<int>{3, nullptr};

  first->next = second; // first->next é um atalho para (*first).next
  second->next = third;
  third->next = forth;

  head = first;

  cout << "Iteration over Linked List" << endl;
  coutAll<int>();

  BynaryNode<int> *toInsert1 = new BynaryNode{8};
  BynaryNode<int> *toInsert2 = new BynaryNode{10};
  cout << endl
       << "Inserting a new node: [" << toInsert1 << "]" << endl
       << "Inserting a new node: [" << toInsert2 << "]" << endl;
  insertAfter(second, toInsert1);
  insertFirst(toInsert2);
  coutAll<int>();

  BynaryNode<int> *toRemove1 = head;
  BynaryNode<int> *toRemove2 = forth;
  cout << endl
       << "Removing a node: [" << toRemove1 << "]" << endl
       << "Removing a node: [" << toRemove2 << "]" << endl;
  remove(toRemove1);
  remove(toRemove2);
  coutAll<int>();

  cout << endl
       << "Head mudou e node foi deletado da memoria" << endl
       << "Head {" << head->data << ", " << head->next << "}" << endl
       << "Del1 {" << toRemove1->data << ", " << toRemove1->next << "}" << endl
       << "Del2 {" << toRemove2->data << ", " << toRemove2->next << "}" << endl;

  constexpr int index = 2;
  constexpr int value = 2;
  const BynaryNode<int> *found1 = findByIndex<int>(index);
  const BynaryNode<int> *found2 = findByValue(value);
  cout << endl
       << "Acessando os elementos i: " << index << ", value: " << value << endl
       << found1 << " {" << found1->data << ", " << found1->next << "}" << endl
       << found2 << " {" << found2->data << ", " << found2->next << "}" << endl;

  return 0;
}
