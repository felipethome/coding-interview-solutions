#include <stdio.h>
#include <stdlib.h>

struct Node {
  Node* small;
  Node* large;
  int val;
  Node(int x) : val(x), small(NULL), large(NULL) {}
};

/*
 * Transform a tree in a circular doubly linked list.
 */
Node* tree_to_list(Node *node);
/*
 * Create a node with the specified value.
 */
Node* create_node(int val);
/*
 * Add a node at the end of the list.
 */
Node* append(Node *head, Node *node);
/*
 * Join two circular doubly linked lists.
 */
Node* join(Node *head1, Node *head2);
/*
 * Free memory used by the list.
 */
void free_list(Node *head);

/* --- Helper functions ---- */

/*
 * Print a particular node followed by line_break.
 */
void print_node(Node *node, char line_break);
/*
 * Print the list.
 */
void print_list(Node *head);
/*
 * Print the list two times.
 */
void print_list_two(Node *head);
/*
 * Print the list two times in reverse order.
 */
void print_list_two_reverse(Node *head);