/**
 * Split a circular list in two equal size halves.
 *
 * Time complexity: O(N), where N is the number of nodes of the given list.
 * Space complexity: O(1).
 *
 * Explanation. you need to get to the middle node and its previous node and the
 * last node. Then, you can make previous node point to head, and last node
 * point to the middle one.
 * To get to the middle you need to have two pointers, one that will be the
 * middle node and another one that will be the last node. "Middle" pointer
 * needs to advance with half the velocity of the "last" pointer.
 */

#include <iostream>
#include <stdlib.h>

#include "../circular-list/list.h"

using namespace std;

ListNode* split_in_half(ListNode *head) {
  ListNode *mid = head, *last = head, *prev = NULL;
  int count = 0;

  if (head == NULL) return NULL;

  while (last->next != head) {
    count++;
    if (count % 2) {
      prev = mid;
      mid = mid->next;
    }
    last = last->next;
  }

  if (prev == NULL) return NULL;

  last->next = mid;
  prev->next = head;

  return mid;
}

int main() {
  ListNode *tmp = NULL, *head = NULL;

  cout << "\nCreating head and assign 0.\n";
  head = create_node(0);
  head->next = head;

  cout << "\nCreating more nine nodes. So we have 10 in total.\n";
  append_nodes(head, 9);

  cout << "\nPrint all elements.\n";
  print_list(head);

  cout << "\nSplit in half.\n";
  ListNode *new_head = split_in_half(head);
  print_list(head);
  print_list(new_head);

  free_list(head);

  return 0;
}