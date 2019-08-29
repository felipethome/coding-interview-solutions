/**
 * Given inorder and preorder traversal of a tree, construct the binary tree.
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the first element of the preorder traversal is the root of the
 * entire tree. So, of course, all the elements after the first element in the
 * preorder vector are children of the root/last element. Now, if we identify
 * how many of these reamining elements are the left children and how many are
 * the right children we can discover which of them are the roots of left and
 * right subtree. The root of the left subtree would be the first element of all
 * the left children, so the element just after the root. And the root of the
 * right subtree will be the first element after the last left child.
 * We discover the number of left and right children using our inorder
 * traversal. From the beginning of the inorder traversal we start to count and
 * when we find our root element we know the number of left children. Now, we
 * start we get how many elements we have after the element we just found to be
 * our root and we till the end of our inorder vector and then we have the
 * number of right children.
 * Repeat the process above for left and right subtree updating variables that
 * you keep to indicate the portion of the preorder and inorder vector you
 * want to investigate.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void _buildTree(vector<int> &inorder, vector<int> &preorder, int s, int e, int x, TreeNode *root) {
  if (s >= e || root == NULL) return;

  int i;

  for (i = s; i <= e; i++) {
    if (inorder[i] == preorder[x]) break;
  }

  int leftSize = i - s;
  int rightSize = e - i;

  if (leftSize > 0) root->left = new TreeNode(preorder[x + 1]);
  if (rightSize > 0) root->right = new TreeNode(preorder[x + leftSize + 1]);

  _buildTree(inorder, preorder, s, i - 1, x + 1, root->left);
  _buildTree(inorder, preorder, i + 1, e, x + leftSize + 1, root->right);
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &preorder) {
  if (preorder.size() == 0 || preorder.size() != inorder.size()) return NULL;

  TreeNode *root = new TreeNode(preorder.front());

  _buildTree(inorder, preorder, 0, preorder.size() - 1, 0, root);

  return root;
}

int main () {
  TreeNode *root = NULL;

  vector<int> inorder = {1, 3, 5, 7, 9, 12, 13, 15, 17};
  vector<int> preorder = {12, 5, 3, 1, 7, 9, 15, 13, 17};
  root = buildTree(inorder, preorder);

  cout << "Level order traversal:" << endl;
  levelorder(root);

  return 0;
}