/*
 * Find the lowest common ancestor of a binary tree (not a binary search tree).
 *
 * Time complexity: O(N), where N is the number of nodes.
 * Space complexity: O(logN), because of the tree height.
 *
 * Explanation:
 * Supposing both of the nodes are present in the tree we can traverse the tree
 * checking if you found one of the nodes you are looking for. If you found
 * return this node. Then, you have three cases:
 *
 * 1. When a function receives NOT NULL from left subtree and NOT NULL from
 * right subtree so the node of that function execution is the ancestor.
 *
 * 2. When the function receives NOT NULL from one of the subtrees (left or
 * right) and NULL from the other, so the current function execution just return
 * the NOT NULL node it received, because this node is one of the nodes we were
 * looking for and it potentially may be the ancestor of itself and the other
 * node.
 *
 * 3. When the function execution receives NULL from both subtrees so we return
 * NULL.
 *
 * Notice, this algorithm also works for the case one of the nodes we are
 * looking for is the lowest common ancestor (look at case 2 above).
 *
 * If the tree may not contain both nodes so we can use a find function to
 * check if the nodes exist. The time and space complexity would remain the
 * same, but in reality we would traverse the tree three times (one to find
 * node N1, another to find node N2 and another to check the ancestor). The
 * other option is to use some variables to indicate if we found both nodes.
 * We also continue to traverse the current branch tree when we find one, but
 * still did not find the other.
 *
 * In a interview you should stick with finding the nodes before applying the
 * LCA algorithm because it is easier, but maybe would be interesting to point
 * that is possible to traverse the tree just one time.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

TreeNode* lca(TreeNode *root, int n1, int n2) {
  if (root == NULL) return NULL;
  if (root->val == n1 || root->val == n2) return root;

  TreeNode *left = lca(root->left, n1, n2);
  TreeNode *right = lca(root->right, n1, n2);

  if (left != NULL && right != NULL) return root;
  if (left == NULL && right == NULL) return NULL;

  return left != NULL ? left : right;
}


// Lowest ancestor modified to accept the case when the values not necessarily
// exist in the tree.
// int _lca(TreeNode *root, int n1, int n2, TreeNode **f1, TreeNode **f2, int t) {
//   if (root == NULL) return t;
//   if (root->val == n1) {
//     // Store N1, so we know we already found it.
//     *f1 = root;
//     // In case we already found N2, we have two options: N2, is the
//     // ancestor of N1 or it is not. If it is not, the actual ancestor will
//     // receive NOT NULL (actually NOT -1) from both sides and return itself,
//     // if it is we will continue to return N2 till the end.
//     if (*f2 != NULL) return (*f2)->val;
//     // If we didn't find N2, then we need to store N1 in a temp variable,
//     // because we need to keep traversing this branch since N2 can be under
//     // N1, but if it is not we eventually will have root == NULL and in this
//     // case we need to return N1 all the way up. Notice the "t" variable is
//     // copied in all calls so just nodes under N1 will see "t" as N1->val.
//     t = root->val;
//   }
//   if (root->val == n2) {
//     // Same logic as above.
//     *f2 = root;
//     if (*f1 != NULL) return (*f1)->val;
//     t = root->val;
//   }

//   int left = _lca(root->left, n1, n2, f1, f2, t);
//   int right = _lca(root->right, n1, n2, f1, f2, t);

//   if (left != -1 && right != -1) return root->val;
//   if (left == -1 && right == -1) return -1;

//   return left != -1 ? left : right;
// }

// int lca(TreeNode *root, int n1, int n2) {
//   TreeNode *f1 = NULL, *f2 = NULL;

//   int lcaValue = _lca(root, n1, n2, &f1, &f2, -1);

//   if (f1 && f2) return lcaValue;

//   return -1;
// }

int main() {
  TreeNode *root = NULL;

  root = new TreeNode(13);

  root->left = new TreeNode(25);
  root->right = new TreeNode(11);

  root->left->right = new TreeNode(36);

  root->left->right->left = new TreeNode(38);
  root->left->right->right = new TreeNode(31);

  root->right->left = new TreeNode(23);
  root->right->right = new TreeNode(12);
  
  root->right->left->left = new TreeNode(2);
  
  root->right->right->right = new TreeNode(32);

  TreeNode *lcaNode = lca(root, 31, 32);

  if (lcaNode) cout << "LCA: " << lcaNode->val << endl;
  else cout << "Ancestor not found." << endl;

  return 0;
}