#ifndef DATA_STRUCTURE_BINARYTREE_HPP
#define DATA_STRUCTURE_BINARYTREE_HPP
#include <iostream>

template <typename T>
class BinaryTree {
  struct Node {
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
  };
  Node* root = nullptr;

 public:
  void clear(Node* node) {
    if (!node) return;

    clear(node->left);
    clear(node->right);
    delete node;
  }

  ~BinaryTree() { clear(root); }

  void setRoot(T value) {
    clear(root);
    root = new Node{value};
  }

  [[nodiscard]] Node* getRoot() const { return root; }

  static Node* insertLeft(Node* parent, T value) {
    if (!parent) return nullptr;
    parent->left = new Node{value};
    return parent->left;
  }

  static Node* insertRight(Node* parent, T value) {
    if (!parent) return nullptr;
    parent->right = new Node{value};
    return parent->right;
  }

  void preorder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }

  void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
  }

  void postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
  }
};

#endif  // DATA_STRUCTURE_BINARYTREE_HPP
