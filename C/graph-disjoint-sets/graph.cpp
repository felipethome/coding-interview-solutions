/**
 * Disjoint Sets With Path Compression.
 *
 * Explanation: disjoint sets are normally used in Kruskal's Algorithm and to
 * find cycles in a graph. It consists of of Abstract Data Type with 3
 * operations:
 * 1. makeSet(val): make a set from a single element.
 * 2. findSet(val): returns the representative element from a set.
 * 3. union(val1, val2): join the sets that val1 and val2 belongs.
 *
 * This is normally achieved with a tree with variable number of children and
 * the basic structure of a Node in a set is:
 * Node {
 *   int rank;     // rank here means the depth of the tree and it is important
 *                 // just for the root node.
 *   int val;      // the data of the node.
 *   Node *parent; // a pointer to the parent node so we can get to the root
 *                 // node
 * }
 *
 * The path compression is performed when findSet() is called and what we want
 * to achive is that every child node points directly to the representative
 * node of the set, in other words, we want one parent whith a lot of direct
 * children. For example:
 * If we have:
 *       1
 *      /
 *     2
 *    /
 *   3
 * We want to have instead:
 *       1
 *      / \
 *     2  3
 * Where 1 is the representative node.
 *
 * Notice that to get a node in O(1) time when the user call one of our 3
 * operations in O(1) time we use a hashmap<key, node>, but to get the root
 * node (representative node) it will not necessarily be constant time if
 * path compression was not performed yet for that node because in this case
 * we gonna use recursion with the parent node to get to the root.
 *
 * Notice too that a rank (the depth of the tree) just grows if both of the
 * settings we are joining have the same rank. In this case we increment rank
 * by 1. If one of the ranks is larger than the other we just use the larger
 * one, so the rank will be the same. For example:
 *      1              4
 *     /      and       \
 *    2                  5
 *   /
 *  3
 * Rank for the left tree is 2 and for the right tree is 1 so we get:
 *      1
 *     / \
 *    2   4
 *   /     \
 *  3       5
 * And the larger rank is still 2.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
  int rank;
  int val;
  Node *parent;
  Node(int x, int y, Node *z) : rank(x), val(y), parent(z) {}
};

unordered_map<int, Node*> nodeMap;

Node *makeSet(int val) {
  Node *n = new Node(0, val, NULL);
  n->parent = n;
  nodeMap[val] = n;

  return n;
}

Node *findSetUtil(Node *n) {
  if (n == n->parent) return n;
  n->parent = findSetUtil(n->parent);
  return n->parent;
}

Node *findSet(int val) {
  if (nodeMap.find(val) != nodeMap.end()) {
    return findSetUtil(nodeMap[val]);
  }
  return NULL;
}

void join(int val1, int val2) {
  Node *n1 = findSet(val1);
  Node *n2 = findSet(val2);

  if (n1 == n2 || !n1 || !n2) return;

  if (n1->rank >= n2->rank) {
    if (n1->rank == n2->rank) (n1->rank)++;
    n2->parent = n1;
  }
  else {
    n1->parent = n2;
  }
}

int main() {
  makeSet(1);
  makeSet(2);
  makeSet(3);
  makeSet(4);
  makeSet(5);
  makeSet(6);
  makeSet(7);

  join(1, 2);
  join(2, 3);
  join(4, 5);
  join(6, 7);
  join(5, 6);
  join(3, 7);

  cout << findSet(1)->val << endl;
  cout << findSet(2)->val << endl;
  cout << findSet(3)->val << endl;
  cout << findSet(4)->val << endl;
  cout << findSet(5)->val << endl;
  cout << findSet(6)->val << endl;
  cout << findSet(7)->val << endl;

  return 0;
}