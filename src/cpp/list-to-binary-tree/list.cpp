/**
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * A height balanced BST: a height-balanced binary tree is defined as a binary
 * tree in which the depth of the two subtrees of every node never differ by
 * more than 1. 
 * 
 * Example:
 *
 * Given A = 1 -> 2 -> 3
 * Return a height balanced BST
 *
 *      2
 *    /   \
 *   1     3
 *
 * Time complexity: O(N), where N is the number of nodes in the given list.
 * Space complexity: O(N).
 *
 * Explanation: the inorder traversal of a binary tree gives the values in
 * ascending order. The list is sorted so if we perform a inorder traversal
 * of the tree before it exists and then construct the tree from bottom to top
 * we get our answer.
 * To perform the inorder traversal we need to know how many nodes we have in
 * the list and then we know that since the tree must be balanced that there
 * will be N / 2 nodes to the left and N / 2 nodes to the right, where N is
 * the number of nodes in the given list. So, if use a variable to control if
 * ew are at the leaf level we can start to return and build our tree getting
 * one node at a time using our inorder traversal.
 */

#include <iostream>
#include <queue>

#include "../linked-list/list.h"
#include "../binary-search-tree/bst.h"

using namespace std;

TreeNode* constructTree(ListNode **curr, int s, int e) {
  if (s == 0 && e == 1) {
    TreeNode *n = new TreeNode(-1);
    n->val = (*curr)->val;
    *curr = (*curr)->next;
    return n;
  }
  if (e - s <= 1) return NULL;

  int m = (s + e) / 2;
  TreeNode *n = new TreeNode(-1);

  n->left = constructTree(curr, s, m);

  n->val = (*curr)->val;
  *curr = (*curr)->next;

  n->right = constructTree(curr, m, e);

  return n;
}

TreeNode* sortedListToBST(ListNode *head) {
  int n = 0;
  ListNode *curr = head;

  while (curr != NULL) {
    n++;
    curr = curr->next;
  }

  curr = head;

  return constructTree(&curr, 0, n);
}

int main() {
  ListNode *head = NULL;
  TreeNode *root = NULL;

  head = create_node(1);
  append(head, 2);
  append(head, 3);
  append(head, 4);
  append(head, 5);
  append(head, 6);
  // append(head, 7);

  print_list(head);

  root = sortedListToBST(head);

  levelorder(root);
  cout << endl;

  return 0;
}
