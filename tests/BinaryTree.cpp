#include "BinaryTree.hpp"

#include <gtest/gtest.h>

TEST(BinaryTreeTest, RootCreation) {
  BinaryTree<int> tree;
  tree.setRoot(10);

  ASSERT_NE(tree.getRoot(), nullptr);
  ASSERT_EQ(tree.getRoot()->data, 10);
}

TEST(BinaryTreeTest, InsertLeftAndRight) {
  BinaryTree<int> tree;
  tree.setRoot(1);

  const auto root = tree.getRoot();
  const auto left = tree.insertLeft(root, 2);
  const auto right = tree.insertRight(root, 3);

  ASSERT_NE(left, nullptr);
  ASSERT_NE(right, nullptr);

  EXPECT_EQ(root->left->data, 2);
  EXPECT_EQ(root->right->data, 3);
}

TEST(BinaryTreeTest, MultipleLevels) {
  BinaryTree<int> tree;
  tree.setRoot(1);

  const auto root = tree.getRoot();
  const auto left = tree.insertLeft(root, 2);
  tree.insertRight(root, 3);

  tree.insertLeft(left, 4);
  tree.insertRight(left, 5);

  EXPECT_EQ(root->left->left->data, 4);
  EXPECT_EQ(root->left->right->data, 5);
}

TEST(BinaryTreeTest, ClearOnResetRoot) {
  BinaryTree<int> tree;
  tree.setRoot(1);
  tree.insertLeft(tree.getRoot(), 2);

  tree.setRoot(200000);

  ASSERT_NE(tree.getRoot(), nullptr);

  EXPECT_EQ(tree.getRoot()->data, 200000);
  EXPECT_EQ(tree.getRoot()->left, nullptr);
  EXPECT_EQ(tree.getRoot()->right, nullptr);
}
