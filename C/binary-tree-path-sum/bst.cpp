/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Example:
 * Given the below binary tree and sum = 22,
 *
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \      \
 *       7    2      1
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: first we need to think how we know we are at the end of a path
 * and that is accomplished checking if both children of a node are NULL.
 * Second, we need to traverse all the paths and we gonna use recursion for
 * that. I choose to first go to the left branch and after to the right branch.
 * We, then, keep a variable of the remaining sum when adding that node to the
 * path (remainingSum = sum - node->val) and call the function for the left
 * and right branchs with remainingSum as input of these calls.
 * If we reach a leaf node (both children NULL) and remaining sum is equal to
 * the node value we return true, else we return false. And our recursion calls
 * are made with an OR, like: hasPathSum(left) || hasPathSum(right).
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

int hasPathSum(TreeNode *root, int sum) {
  if (root == NULL) return 0;

  // We want our sum to end in a leaf, so both children must be NULL.
  if (root->left == NULL && root->right == NULL) {
    if (sum == root->val) return 1;
    else return 0;
  }

  int remainingSum = sum - root->val;

  return hasPathSum(root->left, remainingSum) ||
    hasPathSum(root->right, remainingSum);
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

  if (hasPathSum(root, 40)) cout << "There is a sum" << endl;
  else cout << "There is not a sum" << endl;

  return 0;
}