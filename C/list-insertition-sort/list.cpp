/*
 * Sort a linked list using insertion sort.
 *
 * Time complexity: O(N^2), where N is the size of the list.
 *
 * Explanation: We need to keep a pointer to the last element of the sorted
 * part, call it sorted and initialize it with the head of the list. The element
 * to be sorted in a given iteration will then be sorted->next. We can't go from
 * right to left in a singly linked list, so we need to always go from the head
 * until the unsorted element. While doing this when (curr->val > unsorted->val)
 * we swap the value of the elements. Again, we are swapping values and not
 * nodes. That means we are always swapping the last swapped value with values
 * that are larger than it. Look:
 *
 * Start of the inner loop:
 * c    s    u
 * |    |    |
 * 3 -> 4 -> 2 -> 8
 *
 * First swap:
 *     c,s   u
 *      |    |
 * 2 -> 4 -> 3 -> 8
 *
 * Second swap:
 *      s   c,u
 *      |    |
 * 2 -> 3 -> 4 -> 8
 *
 * Inner loop is now complete because current = unsorted.
 *
 * With c = current, s = sorted, u = unsorted (sorted->next).
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

void swap(ListNode *a, ListNode *b) {
  if (a && b) {
    int t = a->val;
    a->val = b->val;
    b->val = t;
  }
}

ListNode* insertionSortList(ListNode* a) {
  if (!a) return a;

  ListNode *sorted = a;
  
  while (sorted->next != NULL) {
    ListNode *unsorted = sorted->next, *curr = a, *prev = NULL;

    while (curr != unsorted) {
      if (curr->val > unsorted->val) swap(curr, unsorted);
      curr = curr->next;
    }

    sorted = sorted->next;
  }
  
  return a;
}

int main() {
  ListNode *head = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(3);
  append(head, 8);
  append(head, 4);
  append(head, 2);
  append(head, 1);

  print_list(head);

  r = insertionSortList(head);
  cout << "\nAnswer:\n";
  print_list(r);

  free_list(r);

  return 0;
}
