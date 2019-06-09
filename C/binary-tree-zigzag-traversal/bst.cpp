/**
 * Given a binary tree, return the zigzag level order traversal of its nodes’
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 *
 * Example:
 * Given binary tree,
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * return,
 *
 * [
 *   [3],
 *   [20, 9],
 *   [15, 7]
 * ]
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Exaplanation: use two nested while loops, a stack to keep the nodes and a
 * variable to indicate the current direction (left to right or right to left).
 * Also, use a auxiliary stack inside your loop to keep the next nodes. So, you
 * loop through the main stack (that is initialized with root) and print the
 * nodes. For each node you process from the main stack you store its children
 * in the auxiliary stack based on your direction variable. When, the main
 * stack is empty you assign to main stack the auxiliary stack and change
 * direction. If after you assign to the main stack the auxiliary stack the
 * main stack is still empty you stop your loop.
 */

#include <iostream>
#include <queue>
#include <stack>

#include "../binary-search-tree/bst.h"

using namespace std;

void zigzag(TreeNode *root) {
  if (root == NULL) return;

  int dir = 0; // 0 right, -1 left

  stack<TreeNode*> s;
  s.push(root);

  while (true) {
    stack<TreeNode*> t;

    while (!s.empty()) {
      TreeNode* curr = s.top();
      s.pop();

      cout << curr->val << " ";

      if (dir) {
        if (curr->right) t.push(curr->right);
        if (curr->left) t.push(curr->left);
      }
      else {
        if (curr->left) t.push(curr->left);
        if (curr->right) t.push(curr->right);
      }
    }

    dir = ~dir; // 0 to -1, -1 to 0
    s = t;
    if (s.size() == 0) break;
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

  zigzag(root);

  return 0;
}