/*
 * Invert a tree. It is like if you were looking at it in the mirror.
 * 
 * Time complexity: O(N), where N is the number of nodes in the tree.
 * Space complexity: O(logN).
 * 
 * Explanation: to do that just change left and right pointers at each call
 * and then call the function again recursively.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void invert(TreeNode *root) {
  if (root == NULL) return;

  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;

  invert(root->left);
  invert(root->right);
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
  
  // Test inversion
  cout << "Level order traversal before inversion:" << endl;
  levelorder(root);
  cout << endl;
  invert(root);
  cout << "Level order traversal after inversion:" << endl;
  levelorder(root);
  cout << endl;

  return 0;
}