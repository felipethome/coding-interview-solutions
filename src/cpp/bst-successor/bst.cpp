/*
 * Given a BST and a value V, find the successor of this value. Don't use
 * recursion.
 *
 * Time complexity: O(logN), where N is the number of nodes.
 *
 * Explanation: use two BST nodes, one to traverse the tree and another one to
 * keep the successor. If the node you are current in has a value larger than
 * the given value V store this node as the successor and go to the left. If
 * the current node is smaller or equal to V go to the right. 
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

TreeNode* getSuccessor(TreeNode *root, int val) {
  TreeNode *s = NULL, *t = root;

  while (t != NULL) {
    if (t->val > val) {
      s = t;
      t = t->left;
    }
    else if (t->val <= val) {
      t = t->right;
    }
  }

  return s;
}

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

  TreeNode *successor = getSuccessor(root, 12);

  cout << "Successor: " << successor->val << endl;

  return 0;
}