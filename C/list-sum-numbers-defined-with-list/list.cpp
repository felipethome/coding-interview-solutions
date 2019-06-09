/*
 * You are given two linked lists representing two non-negative numbers. The
 * digits are stored in reverse order and each of their nodes contain a single
 * digit. Add the two numbers and return it as a linked list.
 *
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * Time complexity: O(N), where N is the size of the largest list.
 *
 * Explanation: just add the numbers and keep a "carry" variable. Notice, that
 * the result may be longer than the lists you are working with so you need to
 * be sure that carry is zero before exiting the loop. Also, one of the lists
 * can be larger than the other so you will use an OR and not an AND in the loop
 * condition. Return the head of the new list.
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  if(!l1) return l2;
  if(!l2) return l1;

  int carry = (l1->val + l2->val) / 10;
  ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
  ListNode *tail = l3;
  l1 = l1->next;
  l2 = l2->next;

  while(l1 || l2 || carry) {
    int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
    ListNode *t  = new ListNode(sum % 10);
    carry = sum / 10;                                          

    if(l1) l1 = l1->next;
    if(l2) l2 = l2->next;
    tail->next = t;
    tail = t;
  }

  return l3;
}

/*
 * In the following solution I reused the nodes of one of the lists. The
 * exercise actually wants a new list as the result.
 */
// ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
//   ListNode **i = &a, **j = &b;
//   int c = 0, p;
  
//   while (*i != NULL && *j != NULL) {
//     p = (*i)->val;
//     (*i)->val = ((*i)->val + (*j)->val + c) % 10;
//     c = (p + (*j)->val + c) / 10;
//     i = &((*i)->next);
//     j = &((*j)->next);
//   }
  
//   if (*i == NULL && *j != NULL) *i = *j;

//   while (*i != NULL) {
//     p = (*i)->val;
//     (*i)->val = ((*i)->val + c) % 10;
//     c = (p + c) / 10;
//     i = &((*i)->next);
//   }

//   if (c > 0) {
//     *i = b;
//     (*i)->val = c;
//     (*i)->next = NULL;
//   }

//   return a;
// }

int main() {
  ListNode *head = NULL, *head2 = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(8);
  append(head, 8);
  append(head, 8);

  head2 = create_node(9);
  append(head2, 9);
  append(head2, 9);
  append(head2, 9);
  append(head2, 9);

  print_list(head);
  print_list(head2);
  
  r = addTwoNumbers(head, head2);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
