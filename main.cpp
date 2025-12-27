#define LINKED_LIST
#ifdef LINKED_LIST
#include <iostream>
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

/**
Iteration: time complexity: O(n), space: O(1);
@param head Primeiro elemento, ele nos dá acesso à lista toda */
template <typename T> void iterate(Node<T> *head) {
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
template <typename T> void insertFirst(Node<T> *&head, Node<T> *newNode) {
  newNode->next = head;
  head = newNode;
}

/*
exclusion: time complexity: entre O(1) primeiro node, até O(n) ultimo node;
por que temos que atravessar a estrutura até achar o elemento;
[1: 204, 2: 217, 3: 264, --2-3-2--, 4: 252];
{6, 217} -> {5, 264} -> {8, 232} --{-2-,-2-5-2-}--> {3, nullptr}; */
template <typename T> void removeAt(Node<T> *&head, Node<T> *at) {
  if (head == at) {
    head = at->next;
    return delete at;
  }

  for (Node<T> *node = head; node != nullptr; node = node->next)
    if (node->next == at) {
      node->next = node->next->next;
      return delete at;
    }
}

int main() {
  Node<int> *first = new Node{6};
  Node<int> *second = new Node{5};
  Node<int> *third = new Node{2};
  Node<int> *forth = new Node<int>{3, nullptr};

  first->next = second; // first->next é um atalho para (*first).next
  second->next = third;
  third->next = forth;

  Node<int> *head = first;

  cout << "Iteration over Linked List" << endl;
  iterate(head);

  Node<int> *toInsert1 = new Node{8};
  Node<int> *toInsert2 = new Node{10};
  cout << endl
       << "Inserting a new node: [" << toInsert1 << "]" << endl
       << "Inserting a new node: [" << toInsert2 << "]" << endl;
  insertAfter(second, toInsert1);
  insertFirst(head, toInsert2);
  iterate(head);

  Node<int> *toRemove = toInsert2;
  cout << endl << "Removing a node: [" << toRemove << "]" << endl;
  removeAt(head, toRemove);
  iterate(head);

  cout << endl
       << "Head mudou e node foi deletado da memoria" << endl
       << "Head   {" << head->data << ", " << head->next << "}" << endl
       << "deleted{" << toRemove->data << ", " << toRemove->next << "}" << endl;

  return 0;
}
#endif // LINKED_LIST
