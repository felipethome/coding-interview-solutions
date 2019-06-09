/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * Example:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 * The above binary tree is symmetric. 
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: left nodes must be equal to right nodes. So, traverse the tree
 * with two pointers: one at the left, and another at the right. These nodes
 * must have equal val, then when one recursion call ended, call the function
 * again going now to the right of the left pointer and to the left of the right
 * pointer, again the val must be equal.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

bool _isSymmetric(TreeNode *left, TreeNode *right) {
  if (left == NULL && right == NULL) return true;
  if (left == NULL || right == NULL) return false;

  if (left->val != right->val) return false;

  return _isSymmetric(left->left, right->right) &&
    _isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
  if (root == NULL) return true;

  return _isSymmetric(root->left, root->right);
}

int main () {
  TreeNode *root = NULL, *root2 = NULL;

  insert(&root, 12);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 1);
  insert(&root, 9);

  insert(&root2, 1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(2);
  root2->left->left = new TreeNode(3);
  root2->left->right = new TreeNode(3);
  root2->right->left = new TreeNode(3);
  root2->right->right = new TreeNode(3);

  // Test symmetry
  if (isSymmetric(root)) cout << "It is symmetric" << endl;
  else cout << "It is not symmetric" << endl;
  
  // Test symmetry
  if (isSymmetric(root2)) cout << "It is symmetric" << endl;
  else cout << "It is not symmetric" << endl;

  return 0;
}