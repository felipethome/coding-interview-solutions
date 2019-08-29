/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path’s
 * sum is equal to the given sum.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: first we need to think how we know we are at the end of a path
 * and that is accomplished checking if both children of a node are NULL.
 * Second, we need to traverse all the paths and we gonna use recursion for
 * that. I choose to first go to the left branch and after to the right branch.
 * At each node we visit we store it in a vector that we use to store our path.
 * We, then, keep a variable of the remaining sum when adding that node to the
 * path (remainingSum = sum - node->val) and call the function for the left
 * and right branchs with remainingSum as input of these calls.
 * If we reach a leaf node (both children NULL) we store out path in another
 * vector that stores all our paths (so it is a vector of vectors).
 * When we come back from both of our calls (left and right branch) we pop the
 * node we stored in our vector path at that call. Notice we don't pop our nodes
 * after the left branch call, but after the right branch call (or in another
 * words after both of the calls). This is because the right path can
 * potentially use nodes stored by the left branch calls.
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void _allPaths(TreeNode *root, int sum, vector<int> &curr, vector<vector<int>> &ans) {
  if (root == NULL) return;

  curr.push_back(root->val);

  // We want our sum to end in a leaf, so both children must be NULL.
  if (root->left == NULL && root->right == NULL) {
    if (sum == root->val) ans.push_back(curr);
  }
  else {
    int remainingSum = sum - root->val;

    _allPaths(root->left, remainingSum, curr, ans);
    _allPaths(root->right, remainingSum, curr, ans);
  }

  curr.pop_back();
}

vector<vector<int>> allPath(TreeNode *root, int sum) {
  vector<vector<int>> ans;
  vector<int> curr;

  _allPaths(root, sum, curr, ans);

  return ans;
}

int main () {
  TreeNode *root = NULL;

  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(3);

  vector<vector<int>> r = allPath(root, 7);

  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}