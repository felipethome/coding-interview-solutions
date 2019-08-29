/*
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * Example:
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 * Time complexity: O(N), where N is the size of the list.
 *
 * Explanation: Walk over the list. At each iteration keep the previous value.
 * If the previous value is different from the current value keep the current
 * value.
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* a) {
  if (a == NULL) return a;

  ListNode *head = a, *curr = a;
  int prev = curr->val;
  
  a = a->next;
  
  while (a != NULL) {
    if (prev != a->val) {
      curr->next = a;
      curr = curr->next;
    }
    prev = a->val;
    a = a->next;
  }
  
  curr->next = NULL;
  
  return head;
}

int main() {
  ListNode *head = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(1);
  append(head, 1);
  append(head, 2);
  append(head, 3);
  append(head, 3);

  print_list(head);
  
  r = deleteDuplicates(head);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
