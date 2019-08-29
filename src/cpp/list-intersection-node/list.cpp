/*
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 * Example:
 *
 * A:        a1 → a2
 *                  ↘
 *                    c1 → c2 → c3
 *                  ↗
 * B:   b1 → b2 → b3
 *
 * Return c1.
 *
 * Time complexity: O(N), where N is the size of the list.
 *
 * Explanation: The lists may have different sizes. So, we first calculate
 * the size of the lists. If there is a bigger one we get a pointer and walk
 * through the list just enough to be in a node where if this node were the head
 * the two lists would have the same size. Now, we just loop through both lists
 * while their pointers are different. If we find a equal one we return it,
 * otherwise we return NULL.
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
  ListNode *c1 = a, *c2 = b, *r = NULL;
  int n1 = 0, n2 = 0, diff = 0;
  
  while (c1 != NULL || c2 != NULL) {
    if (c1) {
      c1 = c1->next;
      n1++;
    }

    if (c2) {
      c2 = c2->next;
      n2++;
    }
  }
  
  diff = n2 - n1;
  c1 = a;
  c2 = b;

  if (diff < 0) {
    diff *= -1;
    while (diff) {
       diff--;
      c1 = c1->next;
    }
  }
  else {
    while (diff) {
       diff--;
      c2 = c2->next;
    }
  }
  
  while (c1 != c2) {
    c1 = c1->next;
    c2 = c2->next;
  }
  
  if (c1) return c1;
  else return NULL;
}

int main() {
  ListNode *head = NULL, *head2 = NULL, *head3 = NULL, *r = NULL;
  ListNode *last = NULL, *last2 = NULL;

  cout << "Creating...\n";
  head = create_node(2);
  append(head, 3);

  head2 = create_node(1);
  append(head2, 2);
  append(head2, 3);

  head3 = create_node(4);
  append(head3, 5);
  append(head3, 6);

  print_list(head);
  print_list(head2);
  print_list(head3);

  last = get_last(head);
  last2 = get_last(head2);

  last->next = head3;
  last2->next = head3;
  
  r = getIntersectionNode(head, head2);
  cout << "\nAnswer:\n";
  print_node(r, '\n');

  return 0;
}
