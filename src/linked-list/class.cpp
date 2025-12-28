#include <iostream>
using namespace std;

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
  [[nodiscard]] Node *GetTail() const { return tail; }
  [[nodiscard]] int GetLength() const { return length; }

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

  /* O(n) */
  [[nodiscard]] Node *findByValue(const T &value) const {
    for (Node *node = head; node; node = node->next)
      if (node->data == value)
        return node;
    return nullptr;
  }

  /** O(n) */
  void coutAll() const {
    for (Node *node = head; node; node = node->next)
      cout << "[" << node << "] {data: " << node->data << ", "
           << "next: " << node->next << ", "
           << "prev: " << node->prev << "}" << endl;
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

  void clearPrevious() {
    for (Node *node = head; node; node = node->next) {
      node->prev = nullptr;
    }
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

  ~DoubleLinkedList() {
    while (head) {
      const Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
};

#define REVERSE_LINKED_LIST
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

  cout << endl << "Reversed List: " << endl;
  list.reverse();
  list.coutAll();

  return EXIT_SUCCESS;
}
#endif // REVERSE_LINKED_LIST

// #define USUAL_TEST
#ifdef USUAL_TEST
int main() {
  DoubleLinkedList<int> list;

  list.insertLast(3);
  list.insertLast(2);
  list.insertLast(5);
  list.insertLast(6);

  cout << "Iteration over " << list.GetLength() << " elements" << endl;
  list.coutAll();

  constexpr short beforeSecond = 8;
  const auto second = list.getHead()->next;
  cout << endl
       << "Inserting a new node: " << beforeSecond << endl
       << "before node[" << second << "]" << endl;
  list.insertBefore(second, beforeSecond);
  list.coutAll();

  const auto toRemove1 = list.findByIndex(2);
  const auto toRemove2 = list.GetTail();
  if (toRemove1 == toRemove2)
    return EXIT_FAILURE;
  cout << endl
       << "Removing a node: [" << toRemove1 << "]" << endl
       << "Removing a node: [" << toRemove2 << "]" << endl;
  list.remove(toRemove1);
  list.remove(toRemove2);
  list.coutAll();

  constexpr int index = 1;
  constexpr int value = 5;
  const auto found1 = list.findByIndex(index);
  const auto found2 = list.findByValue(value);
  cout << endl
       << "Acessando os elementos i: " << index << ", value: " << value << endl
       << found1 << " {" << found1->data << ", " << found1->next << "}" << endl
       << found2 << " {" << found2->data << ", " << found2->next << "}" << endl;

  return EXIT_SUCCESS;
}
#endif // USUAL_TEST
