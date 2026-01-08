[invert-linkedList]: diagrams/linkedList-invert.excalidraw.png "invert() function singly linked list"
[remove-linkedList]: diagrams/DoubleLinkedList-remove.excalidraw.png "remove() function double linked list"
[example-avlTree]: diagrams/AVLTree-example.excalidraw.png "example of avl tree"
[rotate-AvlTree]: diagrams/AVLTree-RotateRight.excalidraw.png "rotate() function avl tree"
[graphs]: diagrams/graphs.excalidraw.png "graphs"

# Study of Data Structures and Algorithms in C++23
An Educational study of implementations of fundamental data structures and algorithms in C++, featuring linked lists, trees, graphs, and some test coverage using GoogleTest.

## Data Structures Implemented

### Singly Linked List (function.cpp)

![invert-linkedList]

Basic linked list with single direction traversal

Operations: insert, remove, search by index/value

Time Complexity:

- Insert: O(1) at head, O(n) elsewhere
- Remove: O(1) at head, O(n) elsewhere
- Search: O(n)

### Doubly Linked List (DoubleLinkedList.hpp)

![remove-linkedList]

Bidirectional linked list with prev/next pointers

Features: insert before/after, reverse, recursive operations

Time Complexity:

- Insert: O(1) at head/tail/known position
- Remove: O(1) with node pointer
- Search: O(n)

### Double-Ended Queue (DequeLinkedList.hpp)

Linked list-based deque implementation

Operations: insertFront/Rear, deleteFront/Rear, getFront/Rear

Time Complexity: O(1) for all operations

### Binary Tree (BinaryTree.hpp)

![example-avlTree]

Basic binary tree structure

- Traversals: preorder, inorder, postorder
- Operations: insertLeft/Right, clear
- Time Complexity: O(n) for traversals

### AVL Tree (AVLTree.hpp)

![rotate-AvlTree]

Self-balancing binary search tree

Features: automatic balancing, rotations (LL, RR, LR, RL)

Maintains height balance factor `∈ {-1, 0, 1}`

Time Complexity:

- Insert: O(log n)
- Remove: O(log n)
- Search: O(log n)
- Height: O(log n) guaranteed

### Graph (graph.cpp)

![graphs]

Array-based graph with vertices and weighted edges

Supports directed graphs

Operations: addVertex, addEdge, findVertex

Note: Basic implementation, see advanced graph implementation below

## Requirements

Compiler with C++23 support
CMake: 3.20+ for building

Dependencies:

- GoogleTest for unit testing

### Build
cmake --build .

## Usage Examples

### Doubly Linked List

```cpp
#include "DoubleLinkedList.hpp"

int main() {
    DoubleLinkedList<int> list;
    
    // Insert elements
    list.insertLast(10);
    list.insertLast(20);
    list.insertFirst(5);
    
    // Search
    auto node = list.findByValue(20);
    
    // Insert before a node
    list.insertBefore(node, 15);
    
    // Print all elements
    list.coutAll();
    
    // Reverse the list
    list.reverse();
    
    return 0;
}
```

### AVL Tree

```cpp
#include "AVLTree.hpp"

int main() {
    AVLTree<int> tree;
    
    // Insert elements (automatically balanced)
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    
    // Search
    bool found = tree.search(30); // true
    
    // Remove
    tree.remove(20);
    
    // Print in sorted order
    tree.printInorder();
    
    // Print tree structure
    tree.printLevelOrder();
    
    // Check if balanced
    bool balanced = tree.isBalanced(); // always true
    
    return 0;
}
```

### Deque

```cpp
#include "DequeLinkedList.hpp"

int main() {
    DequeLinkedList<std::string> deque;
    
    // Insert at both ends
    deque.insertRear("Middle");
    deque.insertFront("First");
    deque.insertRear("Last");
    
    // Access both ends
    std::string front = deque.getFront(); // "First"
    std::string rear = deque.getRear();   // "Last"
    
    // Remove from both ends
    deque.deleteFront();
    deque.deleteRear();
    
    // Check size
    int size = deque.size();
    
    return 0;
}
```

### Graph

```cpp
#include "Graph.hpp"

int main() {
    // Create undirected weighted graph
    Graph<std::string> cities(false);
    
    // Add edges (cities and distances)
    cities.addEdge("New York", "Boston", 215.0);
    cities.addEdge("New York", "Philadelphia", 95.0);
    cities.addEdge("Boston", "Portland", 103.0);
    
    // Find shortest paths
    auto distances = cities.dijkstra("New York");
    
    // BFS traversal
    auto bfs = cities.BFS("New York");
    
    // Check for cycles
    bool hasCycle = cities.hasCycle();
    
    return 0;
}
```

## Testing

The project includes test suites using GoogleTest

### Test Coverage
- **Factorial**: Edge cases (negative, zero, positive)
- **Deque**: All operations, error handling, empty states
- **Binary Tree**: Creation, insertion, traversals, clearing
- **AVL Tree**: All rotations, balancing, large datasets (8500+ elements)

## Project Structure

```yml
data-structures:
    - include:
        - AVLTree.hpp              # Self-balancing BST
        - BinaryTree.hpp           # Basic binary tree
        - DequeLinkedList.hpp      # Second implementation
        - DoubleLinkedList.hpp     # First implementation
        - Factorial.hpp            # First class to use GoogleTest
    - src:
        - linked-list:
            - function.cpp         # Singly linked list demo
            - class.cpp            # Doubly linked list demo
        - deque.cpp                # Deque demo
        - Graph.cpp                # Basic graph demo
    - tests:
        - Factorial.cpp
        - DequeLinkedList.cpp
        - BinaryTree.cpp
        - AVLTree.cpp
    - CMakeLists.txt
    - README.md
```

## Time Complexity Reference

Data Structure | Insert | Delete | Search | Space
:---|:---:|:---:|:---:|:---:
LinkedList | O(1)/O(n) |O(1)/O(n) | O(n) |O(n)
DLinkedList | O(1) | O(1) | O(n) | O(n)
Deque | O(1) | O(1) | - | O(n)
Binary Tree | O(n) | O(n) | O(n) | O(n)
AVL Tree | O(log n) | O(log n) | O(log n) | O(n)
Graph (Adj List)[^1] | O(1) | O(V+E) | O(V) | O(V+E)

## Learning Path

1. linked-list/function.cpp - Understand basic linked lists using global variables and functions
1. linked-list/class.cpp 
1. DoubleLinkedList.hpp - Learn bidirectional traversal
1. BinaryTree.hpp - Understand tree concepts
1. Explore AVLTree.hpp - Learn self-balancing trees
1. Study DequeLinkedList.hpp - Understand queue variations
1. Practice with test files to see usage patterns
1. Implement Graph.hpp - Master graph algorithms

Optimize and extend existing implementations and create your own data structures

[^1]: O(1) at head/tail with pointer, O(n) otherwise.
