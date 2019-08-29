/*
 * Check if a binary tree is balanced. A binary tree is balanced if the heights
 * of left and right subtree don't differ by more than 1.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: use an auxiliary function to check the heights of the subtrees
 * bottom-up. A empty subtree has height -1. Find the height for the left and
 * right subtree than check if their absolute difference is greater than 1.
 * If it is, mark a variable that you should pass by reference as false. On
 * your main function return this variable.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

int _isBalanced(TreeNode *root, int *ans) {
  if (root == NULL) return -1;

  int leftHeight = _isBalanced(root->left, ans);
  int rightHeight = _isBalanced(root->right, ans);

  if (abs(leftHeight - rightHeight) > 1) *ans = 0;

  return max(leftHeight, rightHeight) + 1;
}

int isBalanced(TreeNode *root) {
  if (root == NULL) return 1;

  int ans = 1;

  _isBalanced(root, &ans);

  return ans;
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

  int balanced = isBalanced(root);

  if (balanced) cout << "Is balanced." << endl;
  else cout << "Not balanced." << endl;

  return 0;
}