/*
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists, and
 * should also be sorted.
 *
 * Example:
 * 5 -> 8 -> 20 
 * 4 -> 11 -> 15
 * Merge list: 4 -> 5 -> 8 -> 11 -> 15 -> 20
 *
 * Time complexity: O(N), where N is the size of the longest list.
 * Explanation: keep two pointers at the beginning of the lists, call them i and
 * j. When j->val < i->val add j to the list and go forward with j.
 * When i->val <= j->val add i to the list and go forward with i.
 */

#include <iostream>

#include "list.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
  ListNode *i = a, *j = b, *curr = NULL, *head = NULL;
  
  // Add the head
  if (a == NULL) return b;
  if (b == NULL) return a;
  
  if (i->val < j->val) {
    head = i;
    i = i->next;
  }
  else {
    head = j;
    j = j->next;
  }
  
  curr = head;
  
  // Merge the elements
  while (i != NULL && j != NULL) {
    if (j->val < i->val) {
      curr->next = j;
      j = j->next;
    }
    else if (i->val <= j->val) {
      curr->next = i;
      i = i->next; 
    }
    curr = curr->next;
  }

  // Add the tail
  if (i) curr->next = i;
  else curr->next = j;
  
  return head;
}

ListNode* create_node(int val) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));

  node->val = val;
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

  last->next = node;
}

void push(ListNode **head, int val) {
  ListNode *node = create_node(val);

  node->next = *head;
  *head = node;
}

void insert_after(ListNode *previous_node, int val) {
  ListNode *new_node = create_node(val);
  ListNode *previous_next = previous_node->next;

  previous_node->next = new_node;
  new_node->next= previous_next;
}

int remove_node(ListNode **head, ListNode* node) {
  ListNode **curr = head;

  while (*curr != node && *curr != NULL) {
    curr = &((*curr)->next);
  }

  if (*curr == node) {
    *curr = node->next;
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
  ListNode *curr = last;

  for (int i = 1; i <= n; i++) {
    curr->next = create_node(i);
    curr = curr->next;
  }
}

void print_node(ListNode *node, char line_break) {
  printf("%d%c", node->val, line_break);
}

void print_list(ListNode *head) {
  ListNode *curr = head;

  while (curr != NULL) {
    print_node(curr, ' ');
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  ListNode *head1 = NULL, *head2= NULL, *r = NULL;

  cout << "Creating...\n";
  head1 = create_node(5);
  append(head1, 8);
  append(head1, 20);

  head2 = create_node(4);
  append(head2, 11);
  append(head2, 15);

  print_list(head1);
  print_list(head2);
  
  r = mergeTwoLists(head1, head2);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
