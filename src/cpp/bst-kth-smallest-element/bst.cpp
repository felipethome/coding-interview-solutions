/**
 * Given a binary search tree, write a function to find the kth smallest
 * element in the tree.
 *
 * NOTE: You may assume 1 <= k <= Total number of nodes in BST.
 *
 * Example:
 * Given, 
 *   2
 *  / \
 * 1   3
 *
 * and k = 2
 *
 * Return 2, as 2 is the second smallest element in the tree.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: just perform inorder traversal. In the place in the code where
 * you would print your nodes in an inorder traversal you start to decrement
 * your k. When k is zero you keep that value and return.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void _kthsmallest(TreeNode* root, int *k, int *val) {
  if (root == NULL) return;

  _kthsmallest(root->left, k, val);
  (*k)--;
  if (*k == 0) {
    *val = root->val;
    return;
  }
  _kthsmallest(root->right, k, val);
}

int kthsmallest(TreeNode* root, int k) {
  int j = k, val;

  _kthsmallest(root, &j, &val);

  return val;
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
  
  int kth = kthsmallest(root, 7);
  cout << "kth: " << kth << endl;

  return 0;
}