/*
 * Given a binary tree, find its minimum depth.
 * Note 1: The minimum depth is the number of nodes along the shortest path from
 * the root node down to the nearest leaf node.
 * Note 2: the path has to end in a left node.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: you must return min(root->left, root->right). The only problem
 * is what you do when left or right subtree is NULL. For example:
 * 1
 *  \
 *   2
 * Has minimum depth 2 and not 1 (we are counting nodes and not edges here
 * because the exercise stated depth as nodes and not edges, also stated paths
 * needs to terminate in a leaf node). If you just return
 * min(root->left, root->right) you would get 1 as answer. So, to address this
 * corner case we identify that we are in a NULL node returning 0 from it and
 * then we can do "if (left == 0 && right != 0) return right + 1;" (same when
 * left != 0).
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

int minDepth(TreeNode *root) {
  if (root == NULL) return 0;

  int left = minDepth(root->left);
  int right = minDepth(root->right);

  if (left == 0 && right != 0) return right + 1;
  else if (left != 0 && right == 0) return left + 1;
  else return min(left, right) + 1;
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

  int r = minDepth(root);

  cout << r << endl;

  return 0;
}