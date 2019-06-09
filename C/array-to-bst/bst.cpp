/*
 * Construct a BST from a sorted array.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: think about binary search. The principle of a binary search is
 * to visualize an array as a BST. The secret is to get the middle element and
 * insert as a root. Then, the middle element of the right part is the root of
 * the right subtree and the middle element of the left part is the root of the
 * left subtree.
 */

#include <iostream>
#include <queue>

#include "bst.h"

using namespace std;

TreeNode* _arrayToBst(vector<int> &a, int s, int e) {
  if (s > e) return NULL;

  int middle = (s + e) / 2;

  TreeNode *n = new TreeNode(a[middle]);

  n->left = _arrayToBst(a, s, middle - 1);
  n->right = _arrayToBst(a, middle + 1, e);

  return n;
}

TreeNode* arrayToBst(vector<int> &a) {
  if (a.size() == 0) return NULL;

  TreeNode *root = _arrayToBst(a, 0, a.size() - 1);

  return root;
}

void insert(TreeNode **root, int val) {
  if (*root == NULL) {
    TreeNode *n = new TreeNode(val);
    *root = n;
  }
  else if (val <= (*root)->val) {
    insert(&((*root)->left), val);
  }
  else {
    insert(&((*root)->right), val);
  }
}

TreeNode* search(TreeNode *root, int val) {
  if (root == NULL) return NULL;

  else if (root->val == val) return root;

  else if (val <= root->val) return search(root->left, val);

  else return search(root->right, val);
}

TreeNode* findMin(TreeNode *root) {
  if (root->left == NULL) return root;
  else return findMin(root->left);
}

TreeNode* findMax(TreeNode *root) {
  if (root->right == NULL) return root;
  else return findMin(root->right);
}

void remove(TreeNode **root, int val) {
  if (*root == NULL) return;
  else if (val < (*root)->val) remove(&((*root)->left), val);
  else if (val > (*root)->val) remove(&((*root)->right), val);
  else {
    if ((*root)->left == NULL && (*root)->right == NULL) {
      delete *root;
      *root = NULL;
    }
    else if ((*root)->left == NULL) {
      TreeNode *temp = *root;
      *root = (*root)->right;
      delete temp;
    }
    else if ((*root)->right == NULL) {
      TreeNode *temp = *root;
      *root = (*root)->left;
      delete temp;
    }
    else {
      TreeNode *min = findMin((*root)->right);
      (*root)->val = min->val;
      remove(&((*root)->right), min->val);
    }
  }
}

/*
 * Level order means we print all the nodes in one level, than all the nodes
 * in the following level and so on. To do that just use a queue.
 */
void levelorder(TreeNode *root) {
  if (root == NULL) return;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *t = q.front();
    cout << t->val << " ";
    if (t->left != NULL) q.push(t->left);
    if (t->right != NULL) q.push(t->right);
    q.pop();
  }
}

/*
 * root, left, right.
 */
void preorder(TreeNode *root) {
  if (root == NULL) return;

  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

/*
 * left, root, right. The result of this traversal is the nodes in sorted order.
 */
void inorder(TreeNode *root) {
  if (root == NULL) return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

/*
 * left, right, root.
 */
void postorder(TreeNode *root) {
  if (root == NULL) return;

  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}

/*
 * The height of a tree is the longest path from the root to one of the leaves.
 * Just traverse the tree and return max(left, right) + 1 for each call. Notice,
 * an empty tree (root == NULL) has height equal -1 per definition.
 *
 * And remember that a path consist of edges, so the height of a node is the
 * number of edges from this node to the most distant leaf.
 */
int findHeight(TreeNode *root) {
  if (root == NULL) return -1;

  int left = findHeight(root->left);
  int right = findHeight(root->right);

  return max(left, right) + 1;
}

int main () {
  TreeNode *root = NULL;
  
  // Test array to BST
  vector<int> a = {3, 6, 7, 10, 13, 15, 20};
  root = arrayToBst(a);
  cout << "Level order traversal:" << endl;
  levelorder(root);
  cout << endl;

  return 0;
}