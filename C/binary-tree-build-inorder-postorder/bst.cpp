/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the last element of the postorder traversal is the root of the
 * entire tree. So, of course, all the elements before the last element in the
 * postorder vector are children of the root/last element. Now, if we identify
 * how many of these reamining elements are the left children and how many are
 * the right children we can discover which of them are the roots of left and
 * right subtree. The root of the left subtree would be the last element of all
 * the left children (so if we know the number of left children we just count
 * from the beginning of the array to get the last left element). We do the
 * same thing for the right subtree starting our count after the last left
 * element (again supposing we know the number of right children).
 * We discover the number of left and right children using our inorder
 * traversal. From the beginning of the inorder traversal we start to count and
 * when we find our root element we know the number of left children. Now, we
 * start we get how many elements we have after the element we just found to be
 * our root and we till the end of our inorder vector and then we have the
 * number of right children.
 * Repeat the process above for left and right subtree updating variables that
 * you keep to indicate the portion of the postorder and inorder vector you
 * want to investigate.
 *
 * This question has bonus points if you solve without recursion. So you should
 * think about that. You can find the code for the non recursive approach below:
 *
 *   // interviewbit.com
 *   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
 *     if(inorder.size() == 0)return NULL;
 *     TreeNode* p;
 *     TreeNode* root;
 *     vector<int> vint;
 *     vector<TreeNode*> vtn;
 *     root = new TreeNode(postorder.back());
 *     vtn.push_back(root);
 *     postorder.pop_back();
 *     while (true) {
 *       if(inorder.back() == vtn.back()->val) {
 *         p = vtn.back();
 *         vtn.pop_back();
 *         inorder.pop_back();
 *         if(inorder.size() == 0) break;
 *         if(vtn.size())
 *             if(inorder.back() == vtn.back()->val)continue;
 *         p->left = new TreeNode(postorder.back());
 *         postorder.pop_back();
 *         vtn.push_back(p->left);
 *       }
 *       else {
 *         p = new TreeNode(postorder.back());
 *         postorder.pop_back();
 *         vtn.back()->right = p;
 *         vtn.push_back(p);
 *       }
 *     }
 *     return root;
 *   }
 */

#include <iostream>
#include <queue>

#include "../binary-search-tree/bst.h"

using namespace std;

void _buildTree(vector<int> &inorder, vector<int> &postorder, int s, int e, int x, TreeNode *root) {
  if (s >= e || root == NULL) return;

  int i;

  for (i = s; i <= e; i++) {
    if (inorder[i] == postorder[x]) break;
  }

  int leftSize = i - s;
  int rightSize = e - i;

  if (leftSize > 0) root->left = new TreeNode(postorder[x - rightSize - 1]);
  if (rightSize > 0) root->right = new TreeNode(postorder[x - 1]);

  _buildTree(inorder, postorder, s, i - 1, x - rightSize - 1, root->left);
  _buildTree(inorder, postorder, i + 1, e, x - 1, root->right);
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
  if (postorder.size() == 0 || postorder.size() != inorder.size()) return NULL;

  TreeNode *root = new TreeNode(postorder.back());

  _buildTree(inorder, postorder, 0, postorder.size() - 1, postorder.size() - 1, root);

  return root;
}

int main () {
  TreeNode *root = NULL;

  vector<int> inorder = {1, 3, 5, 7, 9, 12, 13, 15, 17};
  vector<int> postorder = {1, 3, 9, 7, 5, 13, 17, 15, 12};
  root = buildTree(inorder, postorder);

  cout << "Level order traversal:" << endl;
  levelorder(root);

  return 0;
}