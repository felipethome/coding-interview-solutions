/**
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 * The first call to next() will return the smallest number in BST. Calling
 * next() again will return the next smallest number in the BST, and so on.
 *
 * Notes:
 * 1. next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree.
 * 2. Try to optimize the additional space complexity apart from the amortized
 * time complexity.
 *
 * Time complexity: Amortized O(1), Worst case O(h), where h is the height of
 * the tree.
 *
 * Explanation: the first thing to notice is that they want the amortized
 * complexity to be O(1), which basically means that sometimes will not be O(1).
 * So we can use a stack and in construction time we fill it with all the left
 * nodes from root, which give us a total of O(h) extra memory, where h is the
 * height of the tree. At each time we retrieve a node we re-fill the stack
 * with the right nodes of this just retrieved node.
 */

#include <iostream>
#include <queue>
#include <stack>

#include "../binary-search-tree/bst.h"

using namespace std;

class BSTIterator {
private:
  stack<TreeNode*> s;

public:
  BSTIterator(TreeNode *root) {
    fillStack(root);
  }
  
  bool hasNext() {
    return !s.empty();
  }

  int next() {
    TreeNode *temp = s.top();
    s.pop();

    if (temp->right) fillStack(temp->right);

    return temp->val;
  }

  void fillStack(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      s.push(curr);
      curr = curr->left;
    }
  }
};

int main() {
  TreeNode *root = NULL;

  insert(&root, 12);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 1);
  insert(&root, 9);

  BSTIterator i = BSTIterator(root);
  while (i.hasNext()) cout << i.next() << " ";
  cout << endl;

  return 0;
}