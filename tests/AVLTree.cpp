#include "AVLTree.hpp"

#include "gtest/gtest.h"
#include <string>

class AVLTreeTest : public testing::Test {
protected:
  AVLTree<int> tree;

  void SetUp() override {
    // Fresh tree for each test
  }

  void TearDown() override {
    // Automatic cleanup via destructor
  }
};

TEST_F(AVLTreeTest, IsEmpty) {
  EXPECT_TRUE(tree.isEmpty());
  EXPECT_EQ(tree.getHeight(), 0);
}

TEST_F(AVLTreeTest, Insert) {
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);

  EXPECT_TRUE(tree.search(10));
  EXPECT_TRUE(tree.search(10));
  EXPECT_TRUE(tree.search(20));
  EXPECT_TRUE(tree.search(30));
  EXPECT_EQ(tree.getHeight(), 2);

  EXPECT_FALSE(tree.search(40));
  EXPECT_FALSE(tree.search(-10));
  EXPECT_NE(tree.getHeight(), 3);

  const auto inorder = tree.getInorderTransversal();
  EXPECT_EQ(inorder.size(), 3);
  EXPECT_EQ(inorder.at(0), 10);

  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, RightRotation_ChildLeft_Left_Heavy) {
  tree.insert(30);
  tree.insert(20);
  tree.insert(10);

  EXPECT_TRUE(tree.isBalanced());
  EXPECT_EQ(tree.getHeight(), 2);

  const auto inorder = tree.getInorderTransversal();
  EXPECT_EQ(inorder, std::vector({10, 20, 30}));

  std::cout << "RightRotation ChildLeft Left Heavy" << std::endl;
  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, LeftRotation_ChildRight_Right_Heavy) {
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);

  EXPECT_TRUE(tree.isBalanced());
  EXPECT_EQ(tree.getHeight(), 2);

  const auto inorder = tree.getInorderTransversal();
  EXPECT_EQ(inorder, std::vector({10, 20, 30}));

  std::cout << "LeftRotation ChildRight Right Heavy" << std::endl;
  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, LeftRightRotation) {
  tree.insert(30);
  tree.insert(10);
  tree.insert(20);

  EXPECT_TRUE(tree.isBalanced());
  EXPECT_EQ(tree.getHeight(), 2);

  const auto inorder = tree.getInorderTransversal();
  EXPECT_EQ(inorder, std::vector({10, 20, 30}));

  std::cout << "LeftRightRotation" << std::endl;
  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, RightLeftRotation) {
  tree.insert(10);
  tree.insert(30);
  tree.insert(20);

  EXPECT_TRUE(tree.isBalanced());
  EXPECT_EQ(tree.getHeight(), 2);

  const auto inorder = tree.getInorderTransversal();
  EXPECT_EQ(inorder, std::vector({10, 20, 30}));

  std::cout << "RightLeftRotation" << std::endl;
  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, ComplexBalancing) {
  const std::vector values = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55};

  for (int value : values) {
    tree.insert(value);
    EXPECT_TRUE(tree.isBalanced());
  }

  for (int value : values) {
    EXPECT_TRUE(tree.search(value));
  }

  EXPECT_EQ(tree.getHeight(), 4);

  std::cout << "Complex Balance" << std::endl;
  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, Delete) {
  tree.remove(10);
  EXPECT_TRUE(tree.isEmpty());

  tree.insert(20);
  tree.insert(10);
  tree.insert(30);
  tree.insert(25);
  tree.insert(35);

  tree.remove(20);
  tree.remove(30);
  EXPECT_FALSE(tree.search(20));
  EXPECT_FALSE(tree.search(30));

  EXPECT_TRUE(tree.search(10));
  EXPECT_TRUE(tree.search(25));
  EXPECT_TRUE(tree.search(35));

  EXPECT_TRUE(tree.isBalanced());

  std::cout << "Delete" << std::endl;
  tree.printInorder();
  tree.printLevelOrder();
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, Height_Remain_Logarithmic) {
  constexpr int numberElements = 8512;
  for (int i = 0; i < numberElements; ++i)
    tree.insert(i);

  const int height = tree.getHeight();
  const int expected = ceil(log2(numberElements));
  EXPECT_EQ(height, expected);
  EXPECT_TRUE(tree.isBalanced());

  std::cout << "Height Remain Logarithmic: " << expected << std::endl;
  std::cout << std::endl;
}

TEST_F(AVLTreeTest, Large_Insertion_Sequence) {
  constexpr int MAX = 1000;

  for (int i = 0; i < MAX; ++i)
    tree.insert(i);

  EXPECT_TRUE(tree.isBalanced());

  for (int i = 0; i < MAX; ++i)
    EXPECT_TRUE(tree.search(i));

  std::cout << "Large Insertion Sequence" << std::endl;
  tree.printInorder();
  std::cout << std::endl;
}
