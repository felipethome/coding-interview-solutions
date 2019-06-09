/*
 * Check if a binary tree is a valid binary search tree.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation 1: Traverse the tree in inorder traversal because this would give
 * us the nodes in sorted order. Instead of using a list to keep the nodes and
 * then check if the list is sorted pass to each call the previous node. So,
 * the current node just needs to be smaller than the previous node if it was
 * called from a left subtree, or bigger if it was called from a right subtree
 * (so you also will need a variable to check if the current node is in a left
 * or right branch).
 *
 * Expanation 2: Use a range to check if the current node is valid. The root
 * node can be in the range (-infinity, +infinity). Then, the left node from
 * root node can be in range (-infinity, root->val), and the right node can be
 * in the range (root->val, +infinity). Do that recursively updating the range
 * for each call.
 */

#include <iostream>
#include <queue>
#include <climits>

#include "../binary-search-tree/bst.h"

using namespace std;

// Method 2 
bool _isBST(TreeNode *root, int minValue, int maxValue) {
  if (root == NULL) return true;

  if (root->val > minValue && root->val <= maxValue) {
    bool left = _isBST(root->left, minValue, root->val);
    bool right = _isBST(root->right, root->val, maxValue);

    return left && right;
  }
  else {
    return false;
  }
}

bool isBST(TreeNode *root) {
  return _isBST(root, INT_MIN, INT_MAX);
}

// Method 1 
// bool _isBST(TreeNode *root, TreeNode *prev, bool left) {
//   if (root == NULL) return true;

//   bool c = false;
//   bool l = _isBST(root->left, root, true);

//   if (prev == NULL) {
//     c = true;
//   }
//   else if (left) {
//     if (root->val <= prev->val) c = true;
//   }
//   else {
//     if (root->val > prev->val) c = true;
//   }

//   bool r = _isBST(root->right, root, false);

//   return c && l && r;
// }

// bool isBST(TreeNode *root) {
//   return _isBST(root, NULL, true);
// }

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

  // // Not a binary search tree
  // root = new TreeNode(12);
  // root->left = new TreeNode(8);
  // root->left->left = new TreeNode(9);
  // root->right = new TreeNode(15);
  // root->right->left = new TreeNode(14);
  // root->right->right = new TreeNode(16);

  // Check if binary tree is BST
  if (isBST(root)) cout << "Is binary search tree" << endl;
  else cout << "Is not a binary search tree" << endl;

  return 0;
}