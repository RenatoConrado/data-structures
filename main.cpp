#define LINKED_LIST
#ifdef LINKED_LIST
#include <iostream>
using namespace std;

/*
{} = Node;
[] = referência de memória;
[204, 217, 232, 252];
{6, 217} -> {5, 232} -> {2, 252} -> {3, nullptr}; */
struct Node {
  int data;
  Node *next = nullptr;
};

/**
Iteration: time complexity: O(n), space: O(1);
@param head Primeiro elemento, ele nos dá acesso à lista toda */
void iterate(Node *head) {
  for (Node *node = head; node != nullptr; node = node->next)
    cout << "Node[" << node << "] = { data: " << node->data
         << ", next: " << node->next << " }" << endl;
}

/*
Insertion: time complexity: O(1) por que temos a referencia do elemento;
[1: 204, 2: 217, 3: **264**, 4: 232, 5: 252];
{6, 217} -> {5, 264} -> **{8, 232}** -> {2, 252} -> {3, nullptr}; */
void insertAfter(Node *afterNode, Node *newNode) {
  newNode->next = afterNode->next;
  afterNode->next = newNode;
}

/*
exclusion: time complexity: entre O(1) primeiro node, até O(n) ultimo node;
por que temos que atravessar a estrutura até achar o elemento;
[1: 204, 2: 217, 3: 264, --2-3-2--, 4: 252];
{6, 217} -> {5, 264} -> {8, 232} --{-2-,-2-5-2-}--> {3, nullptr}; */
void removeAt(Node *&head, Node *at) {
  if (head == at) {
    head = head->next;
    return delete at;
  }

  for (Node *node = head; node != nullptr; node = node->next)
    if (node->next == at) {
      node->next = node->next->next;
      return delete at;
    }
}

int main() {
  Node *first = new Node{6};
  Node *second = new Node{5};
  Node *third = new Node{2};
  Node *forth = new Node{3, nullptr};

  first->next = second; // first->next é um atalho para (*first).next
  second->next = third;
  third->next = forth;

  Node *head = first;

  cout << "Iteration over Linked List" << endl;
  iterate(head);

  cout << endl << "Inserting a new node" << endl;
  Node *newThird = new Node{8};
  insertAfter(second, newThird);
  iterate(head);

  cout << endl << "Removing a node" << endl;
  removeAt(head, first);
  iterate(head);

  cout << endl
       << "Head mudou e first foi deletado" << endl
       << "Head{" << head->data << ", " << head->next << "}" << endl
       << "First{" << first->data << ", " << first->next << "}" << endl;

  return 0;
}
#endif // LINKED_LIST
