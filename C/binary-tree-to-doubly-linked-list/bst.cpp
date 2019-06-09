/*
 *                              +-------+
 *                              |       |
 *                              |   4   |
 *                              |       |
 *                   +----------+-------+--------+
 *                   |                           |
 *                   |                           |
 *                   |                           |
 *               +---v---+                   +---v---+
 *               |       |                   |       |
 *               |   2   |                   |   5   |
 *               |       |                   |       |
 *     +---------+-------+---------+         +-------+
 *     |                           |
 *     |                           |
 *     |                           |
 * +---v---+                   +---v---+
 * |       |                   |       |
 * |   1   |                   |   3   |
 * |       |                   |       |
 * +-------+                   +-------+
 *
 * Transform the sorted binary tree in a circular doubly linked list sorted in
 * increasing order.
 *
 * Time complexity: O(N), where N is the number of nodes.
 *
 * Explanation: we need to helper functions. One append a node to a circular
 * doubly linked list, the other joins two doubly linked lists. We traverse the
 * tree in order (first we go all to the left than we start to go to the right).
 * For each of our calls we append the current node in the left list and then
 * we join the left list with the right list. We need to return our left list
 * head in all calls, because the left most node of the tree is the head of our
 * doubly linked list. So, when doing this exercise beside writing the function
 * that does the transformation you also need to wright the append and join
 * helper functions.
 */

#include <iostream>
#include <stdlib.h>

#include "list.h"

using namespace std;

Node *tree_to_list(Node *node) {
  if (node == NULL) return NULL;

  Node *small = tree_to_list(node->small);
  Node *large = tree_to_list(node->large);
  small = append(small, node);
  small = join(small, large);

  return small;
}

Node* append(Node *head, Node *node) {
  if (head != NULL) {
    Node *last = head->small;

    node->large = head;
    node->small = last;

    last->large = node;
    head->small = node;

    return head;
  }
  
  node->small = node;
  node->large = node;

  return node;
}

Node* join(Node *head1, Node *head2) {
  if (head1 != NULL && head2 != NULL) {
    Node *last1 = head1->small;
    Node *last2 = head2->small;

    last1->large = head2;
    head2->small = last1;

    last2->large = head1;
    head1->small = last2;

  }

  return head1;
}

/* --- Helper functions --- */

void print_node(Node *node, char line_break) {
  cout << node->val << line_break;
}

void print_list(Node *head) {
  Node *curr = head;

  do {
    print_node(curr, ' ');
    curr = curr->large;
  } while (curr != head);

  cout << endl;
}

void print_tree(Node *root) {
  Node *curr = root;

  if (root != NULL) {
    print_tree(root->small);
    print_node(root, ' ');
    print_tree(root->large);
  }
}

void print_list_two(Node *head) {
  Node *curr = head;
  int count = 0;

  do {
    print_node(curr, ' ');
    curr = curr->large;

    if (curr == head) count++;
  } while (count < 2);

  cout << endl;
}

void print_list_two_reverse(Node *head) {
  Node *last = head->small;
  Node *curr = last;
  int count = 0;

  do {
    print_node(curr, ' ');
    curr = curr->small;

    if (curr == last) count++;
  } while (count < 2);

  cout << endl;
}

int main() {
  Node *tmp = NULL, *root = NULL;

  cout << "\nCreate tree root (4).\n";
  root = new Node(4);

  cout << "\nCreate the other nodes (2, 1, 3, 5).\n";
  root->small = new Node(2);
  root->large = new Node(5);
  root->small->small = new Node(1);
  root->small->large = new Node(3);

  print_tree(root);
  cout << endl;
  
  cout << "\nCreate the circular doubly linked list.\n";
  Node *head = tree_to_list(root);
  print_list(head);
  print_list_two(head);
  print_list_two_reverse(head);

  return 0;
}
