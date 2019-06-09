/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Tell us the 2 values swapping which the tree will be restored.
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the trick is to traverse the tree inorder. This give us the
 * elements in sorted order. We need to look for anomalies. So we are looking
 * for elements were currentNode->val < previousNode->val, because this should
 * not happen in inorder traversal. When we find this we store our previousNode
 * in a variable node1 and currentNode in a variable node2 and we keeping
 * traverse and if we find this again we replace node2 with the new currentNode.
 *
 * 1, 3, 5, 7, 9, 11, 12, 15, 14, 13, 17
 *
 * We want to have node1 = 15 and node2 = 13. Note that when we find the
 * anomaly 15 > 14 we make node1 = 15 and node2 = 14, because when you switch
 * adjacent elements you would not find any element anymore smaller than its
 * previous element.
 *
 * 1, 3, 5, 7, 9, 11, 13, 12, 14, 15, 17
 *
 * We want to have node1 = 13 and node2 = 12, but note that from 12 onwards
 * everything is normal. Note too that if you find another anormaly after your
 * first one it means you must replace node2 with your new currentNode.
 * 
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void findMistake(TreeNode *root, TreeNode **prev, TreeNode **n1, TreeNode **n2) {
  if (root == NULL) return;

  findMistake(root->left, prev, n1, n2);

  if (*prev && root->val < (*prev)->val) {
    if (*n1 == NULL) {
      *n1 = *prev;
      *n2 = root;
    }
    else {
      *n2 = root;
    }
  }

  *prev = root;

  findMistake(root->right, prev, n1, n2);
}

void fixMistake(TreeNode *root) {
  if (root == NULL) return;

  TreeNode *n1 = NULL, *n2 = NULL, *prev = NULL;

  findMistake(root, &prev, &n1, &n2);

  if (n1 && n2) {
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
  }
}

int main() {
  TreeNode *root = NULL;

  insert(&root, 11);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 12);
  insert(&root, 14);
  insert(&root, 1);
  insert(&root, 9);

  cout << "Levelorder traversal before mistake:" << endl;
  levelorder(root);
  cout << endl;

  int temp = root->right->val;
  root->right->val = root->right->left->val;
  root->right->left->val = temp;
  
  // int temp = root->right->val;
  // root->right->val = root->left->left->left->val;
  // root->left->left->left->val = temp;
  
  // int temp = root->right->val;
  // root->right->val = root->left->right->val;
  // root->left->right->val = temp;

  cout << "Inorder traversal:" << endl;
  inorder(root);
  cout << endl;

  fixMistake(root);

  cout << "After fix inorder traversal:" << endl;
  inorder(root);
  cout << endl;

  return 0;
}