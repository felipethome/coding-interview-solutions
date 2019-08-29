/**
 * Get the middle element of a linked list.
 *
 * Time complexity: O(N), where N is the number of nodes in the linked list.
 * Space complexity: O(1).
 *
 * Explanation: instead of counting the number of nodes and then iterating
 * again over the list until you reach (count / 2)th node, use two pointers.
 * One you use to traverse the list one node at a time, the other you traverse
 * two nodes at a time. When the second pointer arrives to the end of the list
 * the first pointer will at the middle. Return the first point.
 */

#include <iostream>
#include <stdlib.h>

#include "../linked-list/list.h"

using namespace std;

ListNode* get_middle(ListNode *head) {
  ListNode *last = head, *middle = head;

  while (last != NULL && last->next != NULL) {
    /* Move "last" to the next node of the next node. */
    last = last->next->next;
    /* Move "middle" to the next node. */
    middle = middle->next;
  }

  return middle;
}

int main() {
  ListNode *tmp = NULL, *head = NULL;

  // Creating head and assign 0.
  head = create_node(0);

  // Creating more nine nodes. So we have 10 in total.
  append_nodes(head, 9);

  print_list(head);

  cout << "\nGet and print the middle element.\n";
  tmp = get_middle(head);
  print_node(tmp, '\n');

  free_list(head);

  return 0;
}