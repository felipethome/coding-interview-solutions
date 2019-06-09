/**
 * Given a binary tree, print a vertical order traversal of it.
 *
 * Notes:
 * 1. If 2 Tree Nodes share the same vertical level then the one with lesser
 * depth will come first.
 * 2. If 2 Tree Nodes share the same line and depth then the one most to the
 * left will come first.
 * 
 * Example:
 * Given binary tree
 * 
 *       6
 *     /   \
 *    3     7
 *   / \     \
 *  2   5     9
 * 
 * Return
 * 
 * [
 *     [2],
 *     [3],
 *     [6 5],
 *     [7],
 *     [9]
 * ]
 *
 * Time complexity: O(N), where N is the number of nodes in the tree.
 * Space complexity: O(N).
 *
 * Explanation: think about this: can you perform level order traversal and
 * while doing that identify the line which a node belongs?
 *
 * So, we perform level order traversal and for each node at each level we also
 * store its line. Later, we create our answer iterating through our levels
 * and placing each node at the vector storing the nodes for that particular
 * line.
 *
 * The annoying part that lets the code a little ugly is that to know how many
 * lines we have we need to keep the left most line, and the right most line.
 * If we say that root is line 0, then left most line is the line with minimum
 * value (this minimum value will be 0 because of the root or less), and the
 * right most line will be the line with maximum value (will be at least 0
 * because of the root). Now, notice that lines to the left of the root will
 * be negative, so we need to offset them to their correct place in the answer
 * since we don't have negative indexes in our vectors, and for that our
 * offset = abs(leftMostLine). Our total number of lines will be:
 * abs(leftMostLine) + rightMostLine + 1.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

vector<vector<int>> verticalOrderTraversal(TreeNode *root) {
  if (root == NULL) return vector<vector<int>>();

  int leftMostLine = INT_MAX, rightMostLine = INT_MIN;
  vector<vector<pair<int, int>>> levelOrder;
  queue<pair<TreeNode *, int>> qe;

  qe.push({root, 0});

  while (!qe.empty()) {
    queue<pair<TreeNode *, int>> nextQe;
    vector<pair<int, int>> currLevel;

    while (!qe.empty()) {
      TreeNode *currNode = (qe.front()).first;
      int currLine = (qe.front()).second;
      qe.pop();

      leftMostLine = min(leftMostLine, currLine);
      rightMostLine = max(rightMostLine, currLine);

      currLevel.push_back({currNode->val, currLine});

      if (currNode->left) nextQe.push({currNode->left, currLine - 1});
      if (currNode->right) nextQe.push({currNode->right, currLine + 1});
    }

    levelOrder.push_back(currLevel);
    qe = nextQe;
  }

  int offset = abs(leftMostLine);
  int totalLines = offset + rightMostLine + 1;
  vector<vector<int>> ans(totalLines, vector<int>());

  for (int i = 0; i < levelOrder.size(); i++) {
    for (int j = 0; j < levelOrder[i].size(); j++) {
      pair<int, int> curr = levelOrder[i][j];
      ans[curr.second + offset].push_back(curr.first);
    }
  }

  return ans;
}

// O(NlogN) time solution. Calculates the lines and depth and then stable_sort
// by lines and if lines are equal by depth.
// struct NodeInfo {
//   int depth, line, val;
//   NodeInfo(int x, int y, int z) : depth(x), line(y), val(z) {}
// };

// void getNodes(TreeNode *root, int depth, int line, vector<NodeInfo*> &nodes) {
//   if (root == NULL) return;

//   NodeInfo *curr = new NodeInfo(depth, line, root->val);
//   nodes.push_back(curr);

//   getNodes(root->left, depth + 1, line - 1, nodes);
//   getNodes(root->right, depth + 1, line + 1, nodes);
// }

// bool cmp(NodeInfo *n1, NodeInfo *n2) {
//   return n1->line < n2->line ||
//    (n1->line == n2->line && n1->depth < n2->depth);
// }

// vector<vector<int>> verticalTraversal(TreeNode *root) {
//   vector<NodeInfo*> nodes;
//   vector<vector<int>> ans;
//   getNodes(root, 0, 0, nodes);

//   stable_sort(nodes.begin(), nodes.end(), cmp);

//   int i = 0;
//   while (i < nodes.size()) {
//     vector<int> temp;
//     int currLine = nodes[i]->line;

//     while (i < nodes.size() && nodes[i]->line == currLine) {
//       temp.push_back(nodes[i]->val);
//       i++;
//     }
    
//     if (temp.size() > 0) ans.push_back(temp);
//   }

//   return ans;
// }

int main() {
  TreeNode *root = NULL;

  // // Just one node.
  // root = new TreeNode(1);

  // Complete binary tree.
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // // Not a complete binary tree.
  // root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->right->right = new TreeNode(7);

  vector<vector<int>> r = verticalOrderTraversal(root);

  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}