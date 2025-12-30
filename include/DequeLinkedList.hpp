// https://www.geeksforgeeks.org/dsa/implementation-deque-using-doubly-linked-list/
#pragma once
#include <iostream>
#include <sstream>

template <typename T> struct DoubleEndedQueue {
  virtual ~DoubleEndedQueue() = default;

  [[nodiscard]] virtual T getFront() const = 0;
  virtual void insertFront(T item) = 0;
  virtual void deleteFront() = 0;

  [[nodiscard]] virtual T getRear() const = 0;
  virtual void insertRear(T item) = 0;
  virtual void deleteRear() = 0;

  [[nodiscard]] virtual bool isEmpty() const = 0;
  [[nodiscard]] virtual int size() const = 0;
  virtual void clear() = 0;

  [[nodiscard]] virtual std::string toString() const = 0;
};

template <typename T> class DequeLinkedList final : public DoubleEndedQueue<T> {
  struct Node {
    T data;
    Node *next = nullptr;
    Node *prev = nullptr;
  };
  Node *head = nullptr;
  Node *tail = nullptr;
  int length = 0;

  [[nodiscard]] static std::string toString(Node *node) {
    std::ostringstream buffer;
    buffer << "[" << node << "]" << " {data: " << node->data
           << ", next: " << node->next << ", prev: " << node->prev << "}"
           << std::endl;
    return buffer.str();
  }

public:
  [[nodiscard]] T getFront() const override {
    if (!head)
      throw std::runtime_error("Deque vazio");
    return head->data;
  }
  [[nodiscard]] std::string getFrontString() const {
    if (!head)
      throw std::runtime_error("Deque vazio");
    return toString(head);
  }
  void insertFront(T item) override {
    Node *node = new Node{item, head, nullptr};
    if (head)
      head->prev = node;
    else
      tail = node;
    head = node;
    length++;
  }
  void deleteFront() override {
    if (!head)
      return;
    Node *node = head;
    head = head->next;
    if (head)
      head->prev = nullptr;
    else
      tail = nullptr;
    delete node;
    length--;
  }

  [[nodiscard]] T getRear() const override {
    if (!tail)
      throw std::runtime_error("Deque vazio");
    return tail->data;
  }
  [[nodiscard]] std::string getRearString() const {
    if (!tail)
      throw std::runtime_error("Deque vazio");
    return toString(tail);
  }
  void insertRear(T item) override {
    Node *node = new Node{item, nullptr, tail};
    if (tail)
      tail->next = node;
    else
      head = node;
    tail = node;
    length++;
  }
  void deleteRear() override {
    if (!tail)
      return;
    Node *node = tail;
    tail = tail->prev;
    if (tail)
      tail->next = nullptr;
    else
      head = nullptr;
    delete node;
    length--;
  }

  [[nodiscard]] bool isEmpty() const override { return length == 0; }
  [[nodiscard]] int size() const override { return length; }
  void clear() override {
    while (head) {
      const Node *node = head;
      head = head->next;
      delete node;
    }
    tail = nullptr;
    length = 0;
  }

  [[nodiscard]] std::string toString() const override {
    std::ostringstream buffer;
    for (Node *node = head; node; node = node->next) {
      buffer << toString(node);
    }
    return buffer.str();
  }

  ~DequeLinkedList() override { clear(); }
};
