/**
 * Given a binary tree, find the maximum path sum. The path may start and end
 * at any node in the tree.
 * 
 * Example:
 * 
 * Given the below binary tree,
 * 
 *        1
 *       / \
 *      2   3
 * Return 6.
 *
 * Time complexity: O(N), where N is the number of nodes in the tree.
 * Space complexity: O(logN), where logN is the height of the tree.
 *
 * Explanation: first notice this is not exactly a path. You can go up the node
 * you start at, but once you start to go down you can't go up again. In the
 * above example the path would be: 2, 1, 3. So, what we want is the maximum
 * of left, right, parent, left + parent, right + parent, left + parent + right.
 * We start at the bottom left-most node and go up and we always return to the
 * parent node max(left + parent, right + parent). And we keep a variable passed
 * by reference to store the answer.
 */

#include <iostream>
#include <vector>

#include "bst.h"

using namespace std;

int _maxSum(TreeNode *r, int *ans) {
  int left = 0, right = 0;

  // Current, parent
  *ans = max(*ans, r->val);

  if (r->left) {
    left = _maxSum(r->left, ans);
    // Current, left, left + parent
    *ans = max(*ans, max(left, left + r->val));
  }

  if (r->right) {
    // Current, right, right + parent
    right = _maxSum(r->right, ans);
    *ans = max(*ans, max(right, right + r->val));
  }

    // Current, left + parent + right
  if (r->left && r->right) *ans = max(*ans, left + r->val + right);

  if (r->left == NULL) return r->val + right;
  else if (r->right == NULL) return r->val + left;

  return r->val + max(left, right);
}

int maxPathSum(TreeNode *r) {
  if (r == NULL) return 0;

  int ans = INT_MIN;

  _maxSum(r, &ans);

  return ans;
}

// void _maxSum(TreeNode *r, int acc, int *ans) {
//   if (r == NULL) return;

//   if (r->left == NULL && r->right == NULL) *ans = max(*ans, acc + r->val);

//   _maxSum(r->left, acc + r->val, ans);
//   _maxSum(r->right, acc + r->val, ans);
// }

// int maxSum(TreeNode *r) {
//   if (r == NULL) return 0;

//   int acc = 0, ans = INT_MIN;

//   _maxSum(r, acc, &ans);

//   return ans;
// }

int main() {
  TreeNode *root = NULL;
  
  // root = new TreeNode(1);

  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);

  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(4);
  // root->right->right = new TreeNode(3);
  
  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(4);
  // root->left->left->left = new TreeNode(1);
  // root->left->left->right = new TreeNode(1);
  // root->right->right = new TreeNode(3);
  // root->right->right->left = new TreeNode(1);
  // root->right->right->right = new TreeNode(2);
  
  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(4);
  // root->left->left->left = new TreeNode(1);
  // root->left->left->right = new TreeNode(2);
  // root->right->left = new TreeNode(-3);
  
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(-3);
  root->right->left->left = new TreeNode(8);
  
  // root = new TreeNode(-100);
  // root->left = new TreeNode(-200);

  int m = maxPathSum(root);

  cout << "max: " << m << endl;

  return 0;
}