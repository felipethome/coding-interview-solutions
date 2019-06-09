/**
 * Write functions to traverse a binary tree in preorder, inorder and postorder
 * traversal without using recursion.
 *
 * Time complexities: O(N), where N is the number of nodes.
 *
 * Explanation:
 * 
 * Preorder: use a stack, a while loop. Also use a variable to keep the node
 * you are currently dealing with in each iteration. Print the value of the node
 * you are in and go the left. Do that until you find NULL. Then, you pop one
 * node of your stack and start the process again. Do that while your variable
 * with the current node is not NULL OR your stack is not empty.
 *
 * Inorder: use a stack, a while loop. Also use a variable to keep the node
 * you are currently dealing with in each iteration. Store your current node
 * and go to the left. Do that until you find a NULL node. Then, you pop one
 * node of your stack, print its value and go to the right. Then, you repeat
 * the process going to the left again and sotring your nodes. Do that while
 * your variable with the current node is not NULL OR your stack is not empty.
 *
 * Postorder: one easy way to do postorder traversal without using recursion is
 * to do the preorder traversal, store the result in a vector and then print the
 * values of this vector in reversing order.
 * The complicated way that does not use a vector: use a stack, a while loop.
 * Also use a variable to keep the node you are currently dealing with in each
 * iteration. We initialize our variable with the root. Then, in our while we
 * start to store in our stack the left nodes until we find NULL. Then, we get
 * without pop one node from our stack and get its right node. We start the
 * process again. The tricky part is to recognize when we should print.
 * You should print when you are at a right node that does not have any more
 * left nodes that you need to store and then you pop the node your printed.
 */

#include <iostream>
#include <queue>
#include <stack>

#include "../binary-search-tree/bst.h"

using namespace std;

void preorderIterative(TreeNode *root) {
  stack<TreeNode*> s;
  TreeNode *curr = root;

  do {
    if (curr != NULL) {
      s.push(curr);
      cout << curr->val << " ";
      curr = curr->left;
    }
    else {
      curr = (s.top())->right;
      s.pop();
    }
  } while (!s.empty() || curr != NULL);
}

void inorderIterative(TreeNode *root) {
  stack<TreeNode*> s;
  TreeNode *curr = root;

  do {
    if (curr != NULL) {
      s.push(curr);
      curr = curr->left;
    }
    else {
      curr = s.top();
      s.pop();
      cout << curr->val << " ";
      curr = curr->right;
    }
  } while (!s.empty() || curr != NULL);
}

void postorderIterative(TreeNode *root) {
  if (root == NULL) return;

  stack<TreeNode*> s;
  TreeNode *curr = root, *prevCurr = NULL;

  do {
    if (curr != NULL && curr != prevCurr) {
      s.push(curr);
      curr = curr->left;
    }
    else if (curr == s.top()->right) {
      curr = s.top();
      s.pop();
      cout << curr->val << " ";
      prevCurr = curr;
    }
    else {
      curr = s.top()->right;
    }
  } while (!s.empty());
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

  cout << "Inorder recursive: ";
  inorder(root);
  cout << endl;
  cout << "Inorder non recursive: ";
  inorderIterative(root);
  cout << endl;
  cout << endl;

  cout << "Preorder recursive: ";
  preorder(root);
  cout << endl;
  cout << "Preorder non recursive: ";
  preorderIterative(root);
  cout << endl;
  cout << endl;

  cout << "Postorder recursive: ";
  postorder(root);
  cout << endl;
  cout << "Postorder non recursive: ";
  postorderIterative(root);
  cout << endl;

  return 0;
}