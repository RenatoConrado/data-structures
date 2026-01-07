// https://www.geeksforgeeks.org/cpp/implementation-of-graph-in-cpp/
#include <iostream>
#include <ostream>
#include <string>

#define MAX_SIZE 20

struct Edge {
  std::string *start;
  std::string *end;
  int weight;
};

int vertexCount = 0, edgeCount = 0;

std::string vertexList[MAX_SIZE];
Edge edgeList[MAX_SIZE];

bool addVertex(const std::string &name) {
  if (vertexCount >= MAX_SIZE)
    return false;

  vertexList[vertexCount] = name;
  vertexCount++;
  return true;
}

std::string *findVertex(const std::string &name) {
  for (int i = 0; i < vertexCount; ++i)
    if (vertexList[i] == name)
      return &vertexList[i];

  return nullptr;
}

bool addEdge(const std::string &from, const std::string &to, const int weight) {
  if (edgeCount >= MAX_SIZE)
    return false;

  std::string *start = findVertex(from);
  std::string *end = findVertex(to);
  if (!start || !end)
    return false;

  edgeList[edgeCount] = {start, end, weight};
  edgeCount++;
  return true;
}

void printGraph() {
  std::cout << "Vertices:\n";
  for (int i = 0; i < vertexCount; ++i)
    std::cout << " " << vertexList[i] << "\n";

  std::cout << std::endl << "Edges:" << std::endl;
  for (int i = 0; i < edgeCount; ++i)
    std::cout << " " << *edgeList[i].start << " -> " << *edgeList[i].end << " ("
              << edgeList[i].weight << ")\n";
}

int main() {
  addVertex("A");
  addVertex("B");
  addVertex("C");

  addEdge("A", "B", 5);
  addEdge("B", "C", 3);
  addEdge("A", "C", 10);

  printGraph();
}
