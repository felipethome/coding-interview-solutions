/**
 * Implementation of a Doubly Linked List.
 */

#include <iostream>
#include <stdlib.h>

#include "list.h"

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

ListNode* partition(ListNode *head, ListNode *last) {
  int pivot = last->val;
  ListNode *wall = head->prev;

  for (ListNode *curr = head; curr != last; curr = curr->next) {
    if (curr->val <= pivot) {
      wall = (wall == NULL) ? head : wall->next;
      swap(&(curr->val), &(wall->val));
    }
  }

  wall = (wall == NULL) ? head : wall->next;
  swap(&(last->val), &(wall->val));

  return wall;
}

void _quicksort(ListNode *head, ListNode *last) {
  if (last != NULL && head != last && head != last->next) {
    ListNode *pivot_ptr = partition(head, last);
    _quicksort(head, pivot_ptr->prev);
    _quicksort(pivot_ptr->next, last);
  }
}

void quicksort(ListNode *head) {
  ListNode *last = get_last(head);
  _quicksort(head, last);
}

ListNode* create_node(int val) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));

  node->val = val;
  node->prev = NULL;
  node->next = NULL;

  return node;
}

ListNode* get_last(ListNode *head) {
  ListNode *curr = head;

  while (curr->next != NULL) {
    curr = curr->next;
  }

  return curr;
}

void append(ListNode *head, int val) {
  ListNode *last = get_last(head);
  ListNode *node = create_node(val);

  node->prev = last;
  last->next = node;
}

void push(ListNode **head, int val) {
  ListNode *node = create_node(val);

  (*head)->prev = node;
  node->next = *head;
  *head = node;
}

void insert_after(ListNode *previous_node, int val) {
  ListNode *new_node = create_node(val);
  ListNode *previous_next = previous_node->next;

  previous_next->prev = new_node;
  new_node->prev = previous_node;

  previous_node->next = new_node;
  new_node->next= previous_next;
}

// int remove_node(ListNode **head, ListNode* node) {
//   ListNode *curr = *head;

//   while (curr != node && curr != NULL) {
//     curr = curr->next;
//   }

//   if (curr == node) {
//     /* Remove head */
//     if (curr->prev == NULL) {
//       *head = curr->next;
//       (*head)->prev = NULL;
//     }
//     /* Remove last */
//     else if(curr->next == NULL) {
//       curr->prev->next = NULL;
//     }
//     else {
//       curr->prev->next = curr->next;
//       curr->next->prev = curr->prev;
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

  while (*curr != node && *curr != NULL) {
    curr = &((*curr)->next);
  }

  if (*curr == node) {
    *curr = node->next;
    if (node->next != NULL) node->next->prev = node->prev;
    free(node);

    return 1;
  }

  return 0;
}

void free_list(ListNode *head) {
  ListNode *curr = head, *tmp = NULL;

  while (curr != NULL) {
    tmp = curr;
    curr = curr->next;
    free(tmp);
  }
}

/* --- Helper functions --- */

ListNode* get_node(ListNode *head, int n) {
  ListNode *curr = head;
  int i;

  for (i = 0; i < n && curr != NULL; i++) {
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
  ListNode *prev = last;
  ListNode *new_node = NULL;

  for (int i = 1; i <= n; i++) {
    new_node = create_node(i);
    new_node->prev = prev;
    prev->next = new_node;
    prev = new_node;
  }
}

void print_node(ListNode *node, char line_break) {
  cout << node->val << line_break;
}

void print_list(ListNode *head) {
  ListNode *curr = head;

  while (curr != NULL) {
    print_node(curr, ' ');
    curr = curr->next;
  }
  cout << "\n";}

void print_list_reverse(ListNode *head) {
  ListNode *last = get_last(head);
  ListNode *curr = last;

  while (curr != NULL) {
    print_node(curr, ' ');
    curr = curr->prev;
  }
  cout << "\n";
}
