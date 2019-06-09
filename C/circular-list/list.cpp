/**
 * Implementation of a Circular Linked List.
 */

#include <iostream>
#include <stdlib.h>

#include "list.h"

using namespace std;

ListNode* create_node(int val) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));

  node->val = val;
  node->next = NULL;

  return node;
}

ListNode* get_last(ListNode *head) {
  ListNode *curr = head;

  while (curr->next != head) {
    curr = curr->next;
  }

  return curr;
}

void append(ListNode *head, int val) {
  ListNode *last = get_last(head);
  ListNode *node = create_node(val);

  last->next = node;
  node->next = head;
}

void push(ListNode **head, int val) {
  ListNode *node = create_node(val);
  ListNode *last = get_last(*head);

  node->next = *head;
  *head = node;

  last->next = node;
}

void insert_after(ListNode *previous_node, int val) {
  ListNode *new_node = create_node(val);
  ListNode *previous_next = previous_node->next;

  previous_node->next = new_node;
  new_node->next= previous_next;
}

// int remove_node(ListNode **head, ListNode* node) {
//   ListNode *prev = NULL;
//   ListNode *curr = *head;

//   while (curr != node && curr != NULL) {
//     prev = curr;
//     curr = curr->next;
//   }

//   if (curr == node) {
//     if (prev == NULL) {
//       *head = curr->next;
//     }
//     else {
//       prev->next = curr->next;
//     }
//     free(curr);

//     return 1;
//   }

//   return 0;
// }

/*
 * Optimized remove_node(). Instead of pointing to nodes we point to the
 * "next" pointers (or in other words to the pointers that points to nodes).
 */
int remove_node(ListNode **head, ListNode* node) {
  ListNode **curr = head;
  ListNode *last = get_last(*head);

  while (*curr != node && (*curr)->next != *head) {
    curr = &((*curr)->next);
  }

  if (*curr == node) {
    *curr = node->next;
    if (*curr == *head) last->next = node->next;
    free(node);
    return 1;
  }

  return 0;
}

void free_list(ListNode *head) {
  ListNode *curr = head, *tmp = NULL;

  while (curr->next != head) {
    tmp = curr;
    curr = curr->next;
    free(tmp);
  }
}

/* --- Helper functions --- */

ListNode* get_node(ListNode *head, int n) {
  ListNode *curr = head;
  int i;

  for (i = 0; i < n && curr->next != head; i++) {
    curr = curr->next;
  }

  if (i == n) {
    return curr;
  }
  else {
    return NULL;
  }
}

void append_nodes(ListNode *head, int n) {
  ListNode *last = get_last(head);
  ListNode *curr = last;

  for (int i = 1; i <= n; i++) {
    curr->next = create_node(i);
    curr = curr->next;
  }

  curr->next = head;
}

void print_node(ListNode *node, char line_break) {
  cout << node->val << line_break;
}

void print_list(ListNode *head) {
  ListNode *curr = head;

  do {
    print_node(curr, ' ');
    curr = curr->next;
  } while (curr != head);

  cout << "\n";
}