/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * Example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 *
 * Time complexity: O(N), where N is the size of the list.
 *
 * Explanation: Take as an example the list: 1->2->3->4->5->NULL. The reversed
 * list can be seen as: NULL<-1<-2<-3<-4<-5. So we can use a strategy of keeping
 * variables to the previous node, current node, and next node. Then at each
 * iteration we make the current node point to the previous node. Now, we just
 * need to adapt this to reverse a part of the list instead of the whole list.
 * We just need to walk in the list until we find the first node of our partial
 * list and then we reverse until we are at the last of our partial list.
 * Notice that the previous node of the first node of our partial list will
 * need to have its "next" pointer pointing to the correct node (that is the
 * last node of our partial list).
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode *reverseBetween(ListNode *a, int m, int n) {
  if (!a) return a;

  ListNode *prev_node = NULL, *curr_node = a, *next_node = NULL;
  ListNode **before_start = &a;
  int count = 1;

  while (count < m) {
    count++;
    before_start = &(curr_node->next);
    curr_node = curr_node->next;
  }

  while (count <= n) {
    count++;
    next_node = curr_node->next;
    curr_node->next = prev_node;
    prev_node = curr_node;
    curr_node = next_node;
  }

  (*before_start)->next = next_node;
  *before_start = prev_node;

  return a;
}

// ListNode ** _rev(ListNode *c, ListNode **s, ListNode **e, int x, int n) {
//   ListNode **next_p = NULL;

//   if (x == n) {
//     *s = c;
//     *e = c->next;
//     cout << "c: " << c->val << '\n';
//   }
//   else {
//     next_p = _rev(c->next, s, e, x + 1, n);
//     *next_p = c;
//     cout << "c: " << c->val << '\n';
//     cout << "next_p: " << (*next_p)->val << '\n';
//   }

//   return &(c->next);
// }

// ListNode *reverseBetween(ListNode *a, int m, int n) {
//   int x = 1;
//   ListNode *c = a, *s = NULL, *e = NULL;

//   while (x < m - 1) {
//     c = c->next;
//     x++;
//   }

//   ListNode *first = c->next;

//   cout << "x: " << x << " c: " << c->val << '\n';

//   _rev(c->next, &s, &e, x + 1, n);
//   c->next = s;
//   first->next = e;

//   cout << "s: " << s->val << " e: " << e->val << '\n';
//   cout << "first: " << first->val << '\n';

//   return a;
// }

int main() {
  ListNode *head = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(1);
  append(head, 2);
  append(head, 3);
  append(head, 4);
  append(head, 5);

  print_list(head);
  
  r = reverseBetween(head, 2, 4);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
