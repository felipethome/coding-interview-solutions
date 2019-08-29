/**
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * Example:
 *
 * Given,
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * The flattened tree should look like,
 *
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * Note that the left child of all nodes should be NULL.
 *
 * Time complexity: O(N), where N is the number of nodes. Is O(N) because the
 * loop will go through all nodes even if no work is performed in that
 * iteration.
 *
 * Explanation: first thing to note is that this needs to have an order, and
 * looking at the example we can see that this linked list must be build using
 * preorder traversal. Note that the last node to be printed in a preorder
 * traversal is the right most node.
 *
 * Based on this, the last node to be printed from the left subtree is the right
 * most node of the left subtree. The next node to be printed would be the first
 * node from the right subtree. So, we can append the entire right subtree in
 * the right most node of the left subtree and then replace the right subtree of
 * our current node (root in the first iteration) with its left subtree. After,
 * we go one node to the right from the current node and do the same thing. We
 * keep doing this until our current node is NULL.
 */

#include <iostream>
#include <queue>
#include <stack>

#include "../binary-search-tree/bst.h"

using namespace std;

void treeToList(TreeNode *root) {
  TreeNode *curr = root;

  while (curr != NULL) {

    if (curr->left != NULL) {
      TreeNode *rightMost = curr->left;

      while (rightMost->right != NULL) {
        rightMost = rightMost->right;
      }

      rightMost->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }

    curr = curr->right;
  }
}

void specialTraversal(TreeNode *root) {
  TreeNode *curr = root;

  while (curr != NULL) {
    cout << curr->val << " ";
    curr = curr->right;
  }
  cout << endl;
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

  treeToList(root);

  specialTraversal(root);

  return 0;
}