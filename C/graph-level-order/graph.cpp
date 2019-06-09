/**
 * Given a binary tree, return the level order traversal of its nodes’ values.
 * (ie, from left to right, level by level).
 * 
 * Example :
 * Given binary tree,
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *
 * Time complexity: O(N), where N is the number of nodes in the tree.
 * Space complexity: O(M), where M is the number of nodes in the last level
 * of the tree, which is 2^logN.
 *
 * Explanation: just use a queue to save each level. Since the exercise is
 * asking for the answer as a vector of vectors, where each inner vector is
 * a level, we need an auxiliary to save all the nodes in a level without
 * interfering with the nodes that are already in the queue and that are part
 * of the same level. In the end we replace the main queue with the auxiliary
 * queue. In other words, process a level and in another queue save all the
 * children of this level, then, after processing this level, replace the main
 * queue with the auxiliary queue with all children because they are the next
 * level.
 */

#include <iostream>
#include <vector>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> ans;

  if (root == NULL) return ans;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> temp;
    queue<TreeNode *> nextQ;

    while (!q.empty()) {
      TreeNode *t = q.front();
      q.pop();
      temp.push_back(t->val);

      if (t->left != NULL) nextQ.push(t->left);
      if (t->right != NULL) nextQ.push(t->right);
    }

    if (temp.size()) ans.push_back(temp);
    q = nextQ;
  }

  return ans;
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

  vector<vector<int>> r = levelOrder(root);

  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}