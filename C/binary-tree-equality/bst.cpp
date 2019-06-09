/**
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
 *
 * Time complexity: O(N).
 *
 * Explanation: left and right subtrees must be equal.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

bool equal(TreeNode *r1, TreeNode *r2) {
  if (r1 == NULL && r2 == NULL) return true;
  if (r1 == NULL || r2 == NULL) return false;

  if (r1->val != r2->val) {
    return false;
  }
  else {
    bool l = equal(r1->left, r2->left);
    bool r = equal(r1->right, r2->right);

    return l && r;
  }
}

/*
 * Check if two trees are equal (subtrees can be equal to their mirror).
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: left and right subtrees must be equal, but now the subtree can
 * be equal to their mirrors, so this other case is covered with:
 * t1->left == t2->right && t1->right == t2->left.
 */
bool equalMirror(TreeNode *r1, TreeNode *r2) {
  if (r1 == NULL && r2 == NULL) return true;
  if (r1 == NULL || r2 == NULL) return false;

  if (r1->val != r2->val) {
    return false;
  }
  else {
    return (equal(r1->left, r2->left) && equal(r1->right, r2->right)) ||
      (equal(r1->left, r2->right) && equal(r1->right, r2->left));
  }
}

int main () {
  TreeNode *root = NULL, *root2 = NULL, *root3 = NULL;

  insert(&root, 12);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 1);
  insert(&root, 9);

  insert(&root2, 12);
  insert(&root2, 5);
  insert(&root2, 15);
  insert(&root2, 3);
  insert(&root2, 7);
  insert(&root2, 13);
  insert(&root2, 17);
  insert(&root2, 1);
  insert(&root2, 9);

  insert(&root3, 3);
  insert(&root3, 2);
  insert(&root3, 4);
  insert(&root3, 1);
  insert(&root3, 3);
  
  if (equal(root, root2)) cout << "Are equal" << endl;
  else cout << "Not equal" << endl;

  if (equal(root, root3)) cout << "Are equal" << endl;
  else cout << "Not equal" << endl;

  return 0;
}