#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  struct ListNode* next;
  int val;
  ListNode(int x) : val(x), next(NULL) {}
} ListNode;

/*
 * Get the last element of the list.
 */
ListNode* get_last(ListNode *head);
/*
 * Add a node at the end of the list.
 */
void append(ListNode *head, int value);
/*
 * Remove the node.
 */
int remove_node(ListNode **head, ListNode *node);
/*
 * Free memory used by the list.
 */
void free_list(ListNode *head);


/* --- Helper functions ---- */

/*
 * Print a particular node followed by line_break.
 */
void print_node(ListNode *node, char separator);
/*
 * Print the list.
 */
void print_list(ListNode *head);