/*
 * Given a binary tree, find its maximum depth.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the height of a tree is the longest path from the root to one
 * of the leaves. And the height of tree is equal to its maximum depth.
 * Just traverse the tree and return max(left, right) + 1 for each call.
 *
 * This problem is simple and it can be given as a warmup to the minimum depth
 * of a binary tree problem that is a slightly more complicated problem.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

int maxDepth(TreeNode *root) {
  if (root == NULL) return 0;

  int left = maxDepth(root->left);
  int right = maxDepth(root->right);

  return max(left, right) + 1;
}

int main () {
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

  int r = maxDepth(root);

  cout << r << endl;

  return 0;
}