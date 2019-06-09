/*
 * Given a linked list, remove the nth node from the end of list and return
 * its head.
 *
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * The linked list becomes 1->2->3->5.
 *
 * Time complexity: O(N), where N is the size of the list.
 *
 * Explanation: Walk over the list and count its size. Then subtract from the
 * size the value n, call the result c. Then, walk c nodes and remove this node.
 *
 * Another approach, use two pointers pointing to the beginning of the list,
 * call them i and j. Walk with i n nodes. Then, in another loop, walk with i
 * and j simultaneously until i reach the end of the list. Remove the node where
 * j stopped.
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* a, int b) {
  if (a == NULL) return a;

  ListNode **curr = &a;
  int size = 0, c;
  
  while (*curr != NULL) {
    size++;
    curr = &((*curr)->next);
  }
  
  curr = &a;
  c = max(0, size - b);
  
  while(c) {
    curr = &((*curr)->next);
    c--;
  }
  
  *curr = (*curr)->next;
  
  return a;
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
  
  r = removeNthFromEnd(head, 2);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
