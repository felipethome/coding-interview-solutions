/**
 * Given a binary tree:
 *
 * struct TreeLinkNode {
 *   TreeLinkNode *left;
 *   TreeLinkNode *right;
 *   TreeLinkNode *next;
 * }
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Note: each "pointer" is already initialized with NULL.
 *
 * Explanation: the secret is to use the previous level that you just finished
 * completing the "next" pointers to complete the next "next" pointers.
 * So, you start with the root and you make the next pointer of the left child
 * point to the right child. Then, you move to the next level and you get the
 * nodes of this next level traversing the previous one using the next pointers
 * you just filled.
 *
 * In the code below I make the "next" pointer of the left child point to the
 * right child in one iteration. Then in this same iteration I store in a
 * variable the address of the "next" pointer of the right child if this right
 * child is not NULL, otherwise I store the address of the "next" pointer of the
 * left child. So, in the next iteration I can use this address to fill this
 * "next" pointer with the node I'm currently at. Example:
 *
 *   o       o'
 *  / \     / \
 * l   r   l'  r'
 *
 * In one iteration we are checking the children of o, in the next one we are
 * checking the children of o'. So in the next iteration I need to make r point
 * to l', that is why I store the adress of the "next" pointer of r to fill it
 * in the next iteration.
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void populateNextPointers(TreeNode *root) {
  TreeNode *curr = root, *newCurr = NULL;
  TreeNode **n = NULL;

  while (curr != NULL) {
    while (curr != NULL) {
      // Get the first not NULL node of this level.
      if (newCurr == NULL) newCurr = curr->left ? curr->left : curr->right;

      // If we stored a pointer to a "next" pointer try to fill it with a not
      // NULL node.
      if (n != NULL) *n = curr->left ? curr->left : curr->right;

      // If we have a left node try to point it to the right node.
      if (curr->left) curr->left->next = curr->right;

      // Store the pointer to the "next" pointer so we can fill it with the next
      // not NULL node.
      if (curr->right) {
        n = &(curr->right->next);
      }
      else if (curr->left) {
        n = &(curr->left->next);
      }

      curr = curr->next;
    }
    // Move to next level
    curr = newCurr;
    newCurr = NULL;
    n = NULL;
  }
}

void specialTraversal(TreeNode *root) {
  TreeNode *curr = root, *newLeft = NULL;

  while (curr != NULL) {
    newLeft = curr->left;

    while (curr != NULL) {
      cout << curr->val << " ";
      curr = curr->next;
    }

    curr = newLeft;
  }
}

int main () {
  TreeNode *root = NULL;

  // // Complete binary tree
  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);

  // Not a omplete binary tree
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(7);

  populateNextPointers(root);

  specialTraversal(root);

  return 0;
}