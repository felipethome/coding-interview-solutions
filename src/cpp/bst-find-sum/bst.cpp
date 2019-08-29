/**
 * Given a binary search tree T, where each node contains a positive integer,
 * and an integer K, you have to find whether or not there exist two different
 * nodes A and B such that A.value + B.value = K.
 * 
 * Return 1 to denote that two such nodes exist. Return 0, otherwise.
 *
 * Notes:
 * Your solution should run in linear time and not take memory more than
 * O(height of T).
 * Assume all values in BST are distinct.
 *
 * Example:
 *
 *  Input 1: 
 *
 *  T :       10
 *           / \
 *          9   20
 *  
 *  K = 19
 *  
 *  Return: 1
 *  
 *  Input 2: 
 *  
 *  T:        10
 *           / \
 *          9   20
 *  
 *  K = 40
 *  
 *  Return: 0
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: the tricky is to think about the BST as a sorted array. How do
 * you find a sum in a sorted array? You use two pointers: one at the
 * beginning (i) and the other at the end (j) of the array. If a[i] + a[j] > sum
 * decrement j, else if a[i] + a[j] < sum increment i, else it is equal and you
 * found your sum. Now, apply the same idea for the BST using log N extra
 * memory.
 * Use two stacks, one for the left nodes (l) and the other for the right
 * nodes (r). Initialize l with all left nodes from root, and r with all right
 * nodes from root.
 * If l.top() + r.top() > sum pop the right stack and re-fill it with
 * r.top()->left nodes including r.top()->left. Else if l.top() + r.top() < sum
 * pop the left stack and re-fill it with l.top()->right including
 * l.top()->right.
 */

#include <iostream>
#include <queue>
#include <stack>

#include "../binary-search-tree/bst.h"

using namespace std;

void fillLeftStack(TreeNode *root, stack<TreeNode*> &s) {
  TreeNode *temp = root;

  while (temp) {
    s.push(temp);
    temp = temp->left;
  }
}

void fillRightStack(TreeNode *root, stack<TreeNode*> &s) {
  TreeNode *temp = root;

  while (temp) {
    s.push(temp);
    temp = temp->right;
  }
}

bool check2Sum(TreeNode *root, int sum) {
  if (root == NULL) return false;

  stack<TreeNode*> sl;
  stack<TreeNode*> sr;

  fillLeftStack(root, sl);
  fillRightStack(root, sr);

  TreeNode *l = sl.top();
  TreeNode *r = sr.top();

  while (l && r) {
    if (l != r) {
      if (l->val + r->val > sum) {
        sr.pop();
        fillRightStack(r->left, sr);
        r = sr.size() ? sr.top() : NULL;
      }
      else if (l->val + r->val < sum) {
        sl.pop();
        fillLeftStack(l->right, sl);
        l = sl.size() ? sl.top() : NULL;
      }
      else {
        return true;
      }
    }
    else {
      sr.pop();
      fillRightStack(r->left, sr);
      r = sr.size() ? sr.top() : NULL;
    }
  }

  return false;
}

int main() {
  TreeNode *root = NULL;

  insert(&root, 12);
  insert(&root, 13);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 1);
  insert(&root, 9);

  bool sum = check2Sum(root, 26);

  if (sum) cout << "The sum is there." << endl;
  else cout << "The sum is not there." << endl;

  return 0;
}