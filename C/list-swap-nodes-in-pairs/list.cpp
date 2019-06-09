/*
 * Given a linked list, swap every two adjacent nodes and return its head. Your
 * algorithm should use only constant space. You may not modify the values in
 * the list, only nodes itself can be changed.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Time complexity: O(N), where N is the size of the list.
 * Explanation: Keep a pointer to the "next" pointer of the second node of a
 * pair of nodes, call it c. At each iteration we swap the "next" pointers of
 * our pair and also the content of the "next" pointer we are pointing with c.
 *
 * c (so *c = address of the first node)
 * |
 * h -> next -> next -> next -> next
 *       1       2       3       4
 *
 *               c (so *c = address pointed by the
 *               |  "next" pointer of the second node)
 *               |
 * h -> next -> next -> next -> next
 *       1       2       3       4
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

// Obs: You can use a dummy node for the head to get rid of the special case.
ListNode* swapPairs(ListNode* a) {
  if (!a) return a;

  ListNode **c = &a;

  while (*c != NULL && (*c)->next != NULL) {
    ListNode *l = *c, *r = (*c)->next, *t = NULL;

    *c = r;
    l->next = r->next;
    r->next = l;

    c = &((*c)->next->next);
  }

  return a;
}

int main() {
  ListNode *head = NULL, *head2 = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(1);
  append(head, 2);
  append(head, 3);
  append(head, 4);
  append(head, 5);
  append(head, 6);
  append(head, 7);
  append(head, 8);

  print_list(head);

  head2 = create_node(1);
  append(head2, 2);
  append(head2, 3);
  append(head2, 4);
  append(head2, 5);
  append(head2, 6);
  append(head2, 7);

  print_list(head2);
  
  r = swapPairs(head);
  cout << "\nAnswer:\n";
  print_list(r);

  r = swapPairs(head2);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
