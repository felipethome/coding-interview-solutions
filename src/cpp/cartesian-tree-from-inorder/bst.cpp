/**
 * Given an inorder traversal of a cartesian tree, construct the tree.
 * 
 * Cartesian tree: is a heap ordered binary tree, where the root is greater
 * than all the elements in the subtree.
 *
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Example:
 * Given, [1 2 3]
 * 
 * Return,   
 *           3
 *          /
 *         2
 *        /
 *       1
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the first thing to notice is that inorder traversal here doesn't
 * means the elements in the array is in sorted order because this is not a
 * binary search tree. Nonetheless, whoever is our root all the elements to
 * the left of it are their left children and all the elements to its right are
 * their right children. So, we can use recursion with two variables in our
 * function call keeping which portion of the array we are dealing with. At each
 * call we find out who is our root with a "for" loop. Then we can our function
 * again updating our limits variable to be:
 * start .. root index - 1
 * root index + 1 .. end
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

TreeNode* _buildCartesianTree(vector<int> &inorder, int s, int e) {
  if (s > e) return NULL;

  int i, maxValue = -1, maxIdx;

  for (i = s; i <= e; i++) {
    if (inorder[i] > maxValue) {
      maxIdx = i;
      maxValue = inorder[i];
    }
  }

  TreeNode *root = new TreeNode(inorder[maxIdx]);

  int leftSize = maxIdx - s;
  int rightSize = e - maxIdx;

  if (leftSize > 0) {
    root->left = _buildCartesianTree(inorder, s, maxIdx - 1);
  }
  if (rightSize > 0) {
    root->right = _buildCartesianTree(inorder, maxIdx + 1, e);
  }

  return root;
}

TreeNode* buildCartesianTree(vector<int> &inorder) {
  if (inorder.size() == 0) return NULL;

  return _buildCartesianTree(inorder, 0, inorder.size() - 1);
}

int main () {
  TreeNode *root = NULL;
  
  // // Cartesian tree
  // root = new TreeNode(10);
  // root->left = new TreeNode(9);
  // root->right = new TreeNode(8);
  // root->left->left = new TreeNode(7);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(5);

  // vector<int> ino = {2, 1, 3};
  vector<int> ino = {7, 9, 10, 6, 8, 5};
  root = buildCartesianTree(ino);

  cout << "Level order traversal:" << endl;
  levelorder(root);
  cout << endl;

  return 0;
}