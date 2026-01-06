#pragma once

#include <algorithm>
#include <concepts>
#include <iostream>
#include <queue>

template <typename T>
concept Comparable = requires(T a, T b) {
  { a < b } -> std::convertible_to<bool>;
  { a > b } -> std::convertible_to<bool>;
  { a == b } -> std::convertible_to<bool>;
};

template <Comparable T> class AVLTree {
  struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 1;
    explicit Node(const T &value) : data(value) {}
  };
  Node *root = nullptr;

  [[nodiscard]] static int getHeight(const Node *node) {
    return node ? node->height : 0;
  }

  [[nodiscard]] static int getBalanceFactor(const Node *node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
  }

  static void updateHeight(Node *node) {
    if (!node)
      return;
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
  }

  /**
   * @return new root *Node
   * @details RIGHT ROTATION, fix left-heavy
   * @code
         node                c1
         /  \               /  \
        c1   c2    -->   c1c1   node
       / \                     / \
    c1c1 c1c2               c1c2   c2 @endcode */
  [[nodiscard]] static Node *rotateRight(Node *node) {
    Node *c1 = node->left;
    Node *c1c2 = c1->right;

    c1->right = node;
    node->left = c1c2;

    updateHeight(node);
    updateHeight(c1);

    return c1;
  }

  /**
   * @return new root *Node
   * @details LEFT ROTATION, fix right-heavy
   * @code
       node                c2
       /  \               /  \
      c1   c2    -->    node  c2c2
           / \          / \
        c2c1 c2c2    c1  c2c1 @endcode */
  [[nodiscard]] static Node *rotateLeft(Node *node) {
    Node *c2 = node->right;
    Node *c2c1 = c2->left;

    c2->left = node;
    node->right = c2c1;

    updateHeight(node);
    updateHeight(c2);

    return c2;
  }

  [[nodiscard]] static Node *balance(Node *node) {
    if (!node)
      return nullptr;

    updateHeight(node);
    const int nodeBF = getBalanceFactor(node);
    const int leftBF = getBalanceFactor(node->left);
    const int rightBF = getBalanceFactor(node->right);

    // left-heavy and (childLeft-balanced or childLeft-left-heavy)
    if (nodeBF > 1 && leftBF >= 0) {
      return rotateRight(node);
    }
    // right-heavy and (childRight-balanced or childRight-right-heavy)
    if (nodeBF < -1 && rightBF <= 0) {
      return rotateLeft(node);
    }
    // Left-heavy and childLeft-right-heavy
    // left rotation on child, then right rotation
    if (nodeBF > 1 && leftBF < 0) {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }
    // Right-Left and childRight-left-heavy
    // (right rotation on child, then left rotation)
    if (nodeBF < -1 && rightBF > 0) {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }
    return node;
  }

  [[nodiscard]] static Node *insert(Node *node, const T &value) {
    if (!node)
      return new Node(value);

    if (value < node->data)
      node->left = insert(node->left, value);
    else if (value > node->data)
      node->right = insert(node->right, value);
    else
      return node; // Duplicates not allowed

    return balance(node); // Balance after insertions
  }

  [[nodiscard]] static Node *findMinValue(Node *node) {
    while (node && node->left)
      node = node->left;
    return node;
  }

  [[nodiscard]] static Node *remove(Node *node, const T &value) {
    if (!node)
      return nullptr;

    if (value < node->data)
      node->left = remove(node->left, value);
    else if (value > node->data)
      node->right = remove(node->right, value);
    else {
      if (!node->left || !node->right) { // 0 or 1 child
        Node *temp = node->left ? node->left : node->right;
        delete node;
        return temp;
      } else { // 2 children
        Node *temp = findMinValue(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
      }
    }

    return balance(node);
  }

  [[nodiscard]] static bool search(Node *node, const T &value) {
    if (!node)
      return false;

    if (value == node->data)
      return true;
    if (value < node->data)
      return search(node->left, value);

    return search(node->right, value);
  }

  // sorted order
  static void inorder(Node *node) {
    if (!node)
      return;

    inorder(node->left);
    std::cout << node->data << ", ";
    inorder(node->right);
  }

  static void inorderVector(Node *node, std::vector<T> &result) {
    if (!node)
      return;

    inorderVector(node->left, result);
    result.push_back(node->data);
    inorderVector(node->right, result);
  }

  // level-order, visualize tree.
  static void levelOrder(Node *node) {
    if (!node)
      return;

    std::queue<Node *> queue;
    queue.push(node);

    while (!queue.empty()) {
      const int size = queue.size();

      for (int i = 0; i < size; ++i) {
        Node *current = queue.front();
        queue.pop();
        std::cout << current->data << " ";

        if (current->left)
          queue.push(current->left);
        if (current->right)
          queue.push(current->right);
      }

      std::cout << "\n";
    }
  }

  [[nodiscard]] static bool isBalanced(const Node *node) {
    if (!node)
      return true;
    const int balance = getBalanceFactor(node);
    if (balance < -1 || balance > 1)
      return false;
    return isBalanced(node->left) && isBalanced(node->right);
  }

  [[nodiscard]] static size_t size(const Node *node) {
    if (!node)
      return 0;
    return 1 + size(node->left) + size(node->right);
  }

  static void clean(const Node *node) {
    if (!node)
      return;
    clean(node->left);
    clean(node->right);
    delete node;
  }

public:
  explicit AVLTree() {}

  ~AVLTree() { clean(root); }

  void insert(const T &value) { root = insert(root, value); }

  void remove(const T &value) { root = remove(root, value); }

  [[nodiscard]] bool search(const T &value) const {
    return search(root, value);
  }

  void printInorder() const {
    std::cout << "Inorder: { ";
    inorder(root);
    std::cout << "}" << std::endl;
  }

  void printLevelOrder() const {
    std::cout << "Level Order:" << std::endl;
    levelOrder(root);
  }

  std::vector<T> getInorderTransversal() {
    std::vector<T> result;
    inorderVector(root, result);
    return result;
  }

  [[nodiscard]] int getHeight() const { return getHeight(root); }

  [[nodiscard]] bool isEmpty() const { return root == nullptr; }

  [[nodiscard]] bool isBalanced() const { return isBalanced(root); }

  [[nodiscard]] size_t getSize() const { return size(root); }
};
