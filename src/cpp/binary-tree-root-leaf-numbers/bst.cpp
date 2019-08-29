/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers % 1003.
 *
 * Example:
 *
 *     1
 *    / \
 *   2   3
 *
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the numbers are represented from root to leaf. So, one simple
 * solution is to calculate each of these numbers, sum them, and then take the
 * remainder. The problem with this solution is the overflow. The reason our
 * numbers are stored using tree nodes is probably because they are so big they
 * can not fit in a 32-bit or even 64-bit variable.
 * So, since we need the sum modulo 1003 we need to take advantage of this.
 *
 * Our number would be calculated doing:
 * (currentNumber * 10) + node->val.
 * If some analysis we find out that we can make:
 * ((currentNumber * 10) + node->val) % 1003.
 *
 * Now, we have all our numbers modulo 1003, but this is not enough because we
 * can have so many of these numbers that our sum can still overflow. So,
 * we also need to make our sum modulo 1003. So, every time we achieve a leaf
 * we add to our sum like this:
 * sum = (sum + num) % 1003.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void _allPathSum(TreeNode *root, int num, int *sum) {
  if (root == NULL) return;

  num = ((num * 10) + root->val) % 1003;

  // We want our sum to end in a leaf, so both children must be NULL.
  if (root->left == NULL && root->right == NULL) {
    *sum = (*sum + num) % 1003;
  }
  else {
    _allPathSum(root->left, num, sum);
    _allPathSum(root->right, num, sum);
  }
}

int allPathSum(TreeNode *root) {
  int sum = 0;
  int num = 0;

  // Notice, num is not passed by reference so we have a distinct num variable
  // to work with at each call of _allPathSum.
  _allPathSum(root, num, &sum);

  return sum;
}

int main () {
  TreeNode *root = NULL;

  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(4);
  // root->right->right = new TreeNode(3);
  
  root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->right = new TreeNode(6);

  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(8);

  int sum = allPathSum(root);

  cout << "Sum: " << sum << endl;

  return 0;
}