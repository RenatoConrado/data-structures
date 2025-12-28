#include <iostream>
using namespace std;

template <typename T> class LinkedList {
  struct Node {
    T data;
    Node *next;
  };

  Node *head = nullptr;

public:
  /** O(n) */
  void coutAll() const {
    for (Node *node = head; node; node = node->next)
      cout << "[" << node << "] {data: " << node->data
           << ", next: " << node->next << "}" << endl;
  }

  /** O(1) */
  void insertFirst(T value) { head = new Node{value, head}; }

  /** O(1) */
  static void insertAfter(Node *after, T value) {
    if (!after)
      return;
    after->next = new Node{value, after->next};
  }

  /** O(n) */
  void remove(Node *node) {
    if (!head || !node)
      return;

    if (head == node) {
      head = head->next;
      return delete node;
    }

    for (Node *current = head; current->next; current = current->next) {
      if (current->next == node) {
        current->next = node->next;
        return delete node;
      }
    }
  }

  /* O(n) */
  [[nodiscard]] Node *findByIndex(const int index) const {
    int i = 0;
    for (Node *node = head; node; node = node->next) {
      if (i == index)
        return node;
      ++i;
    }
    return nullptr;
  }

  /* O(n) */
  [[nodiscard]] Node *findByValue(const T &value) const {
    for (Node *node = head; node; node = node->next)
      if (node->data == value)
        return node;
    return nullptr;
  }

  [[nodiscard]] Node *getHead() const { return head; }

  ~LinkedList() {
    while (head) {
      const Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
};

int main() {
  LinkedList<int> list;

  list.insertFirst(3);
  list.insertFirst(2);
  list.insertFirst(5);
  list.insertFirst(6);

  cout << "Iteration over Linked List" << endl;
  list.coutAll();

  constexpr short afterSecond = 8;
  const auto second = list.findByIndex(1);
  cout << endl
       << "Inserting a new node: " << afterSecond << endl
       << "After node[" << second << "]" << endl;
  LinkedList<int>::insertAfter(second, afterSecond);
  list.coutAll();

  const auto toRemove1 = list.getHead();
  const auto toRemove2 = list.findByValue(3);
  cout << endl
       << "Removing a node: [" << toRemove1 << "]" << endl
       << "Removing a node: [" << toRemove2 << "]" << endl;
  list.remove(toRemove1);
  list.remove(toRemove2);
  list.coutAll();

  constexpr int index = 2;
  constexpr int value = 2;
  const auto found1 = list.findByIndex(index);
  const auto found2 = list.findByValue(value);
  cout << endl
       << "Acessando os elementos i: " << index << ", value: " << value << endl
       << found1 << " {" << found1->data << ", " << found1->next << "}" << endl
       << found2 << " {" << found2->data << ", " << found2->next << "}" << endl;

  return 0;
}
