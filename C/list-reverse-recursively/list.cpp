/*
 * Reverse a linked list with recursion.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 5->4->3->2->1->NULL.
 *
 * Time complexity: O(N), where N is the size of the list.
 *
 * Explanation: My strategy is to return a pointer to the "next" pointer of each
 * node.
 * I stop the recursion when the "next" pointer of my current node is
 * NULL, or in other words when the current node is the last node. Then, I start
 * to return the "next" pointer. And I make the "next" pointer point to the
 * current node. But there is a problem: the head needs to point to the last
 * node of the list, so I also pass a pointer to a pointer that will point to
 * the new head and in the base case (when we are at the last node) I make this
 * pointer point to the last node.
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode **_rev(ListNode *a, ListNode **h) {
  if (a->next == NULL) {
    *h = a;
    return &(a->next);
  }
  else {
    ListNode **pn = _rev(a->next, h);
    *pn = a;
    return &(a->next);
  }
}

ListNode *reverseList(ListNode *a) {
  if (a == NULL) return a;
  else {
    ListNode *h = NULL;
    ListNode **pn = _rev(a, &h);
    *pn = NULL;
    return h;
  }
}

int main() {
  ListNode *head = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(1);
  append(head, 2);
  append(head, 3);
  append(head, 4);
  append(head, 5);

  print_list(head);
  
  r = reverseList(head);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
