#pragma once
#include <iostream>

template <typename T> class DoubleLinkedList {
  struct Node {
    T data;
    Node *next = nullptr;
    Node *prev = nullptr;
  };

  Node *head = nullptr;
  Node *tail = nullptr;
  int length = 0;

public:
  [[nodiscard]] Node *getHead() const { return head; }
  [[nodiscard]] Node *getTail() const { return tail; }
  [[nodiscard]] int getLength() const { return length; }

  /** O(n) */
  [[nodiscard]] Node *findByIndex(const int index) const {
    if (index > length - 1 || index < 0)
      return nullptr;
    int i = 0;
    for (Node *node = head; node; node = node->next, ++i)
      if (i == index)
        return node;
    return nullptr;
  }

  /** O(n) */
  [[nodiscard]] Node *findByValue(const T &value) const {
    for (Node *node = head; node; node = node->next)
      if (node->data == value)
        return node;
    return nullptr;
  }

  static void coutNode(Node *node) {
    std::cout << "[" << node << "] {data: " << node->data << ", "
              << "next: " << node->next << ", "
              << "prev: " << node->prev << "}" << std::endl;
  }

  /** O(n) */
  void coutAll() const {
    for (Node *node = head; node; node = node->next)
      coutNode(node);
    std::cout << std::endl;
  }

  /** O(1) */
  void insertFirst(T value) {
    Node *node = new Node{value, head};
    if (head)
      head->prev = node;
    else // primeiro elemento a ser inserido
      tail = node;
    head = node;
    length++;
  }

  /** O(1) */
  void insertLast(T value) {
    Node *node = new Node{value, nullptr, tail};
    if (tail)
      tail->next = node;
    else // primeiro elemento a ser inserido
      head = node;
    tail = node;
    length++;
  }

  /** O(1) */
  void insertAfter(Node *prev, T value) {
    if (!prev)
      return;

    Node *node = new Node{value, prev->next, prev};
    if (prev->next)
      prev->next->prev = node;
    else // inserindo depois do ultimo elemento
      tail = node;

    prev->next = node;
    length++;
  }

  /** O(n) */
  void insertAfter(const int index, T value) {
    insertAfter(findByIndex(index), value);
  }

  /** O(1) */
  void insertBefore(Node *next, T value) {
    if (!next)
      return;

    Node *node = new Node{value, next, next->prev};
    if (next->prev)
      next->prev->next = node;
    else // inserindo antes do primeiro elemento
      head = node;

    next->prev = node;
    length++;
  }

  /** O(n) */
  void insertBefore(const int index, T value) {
    insertBefore(findByIndex(index), value);
  }

  /** O(1) */
  void remove(Node *node) {
    if (!node)
      return;

    if (node->prev)
      node->prev->next = node->next;
    else // primeiro elemento não tem anterior
      head = node->next;

    if (node->next)
      node->next->prev = node->prev;
    else // ultimo elemento não tem proximo
      tail = node->prev;

    delete node;
    length--;
  }

  /** Simula uma linked list ligada apenas com next */
  void clearPrevious() {
    for (Node *node = head; node; node = node->next) {
      node->prev = nullptr;
    }
    tail = nullptr;
  }

  /** Using recursion to print elements in reverse order */
  static void printReverse(Node *node) {
    if (node->next)
      printReverse(node->next);
    coutNode(node);
  }

  void reverse() {
    Node *prev = nullptr;
    for (Node *next, *node = head; node; node = next) {
      next = node->next;
      node->next = prev;
      prev = node;
    }
    head = prev;
  }

  void reverseUsingRecursion(Node *node, Node *prev = nullptr) {
    head = node;
    if (node->next)
      reverseUsingRecursion(node->next, node);
    node->next = prev;
  }

  ~DoubleLinkedList() {
    while (head) {
      const Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
};
