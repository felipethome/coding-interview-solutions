#include <iostream>
#include <stdlib.h>

#include "../linked-list/list.h"

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

ListNode* partition(ListNode *head, ListNode *prev, ListNode *last) {
  int pivot = last->val;
  ListNode *wall = prev;

  for (ListNode *curr = head; curr != last; curr = curr->next) {
    if (curr->val <= pivot) {
      wall = (wall == NULL) ? head : wall->next;
      swap(&(curr->val), &(wall->val));
    }
  }

  ListNode *pivot_ancestor = wall;
  wall = (wall == NULL) ? head : wall->next;
  swap(&(last->val), &(wall->val));

  return pivot_ancestor;
}

void _quicksort(ListNode *head, ListNode *prev, ListNode *last) {
  if (last != NULL && head != last && head != last->next) {
    ListNode *pivot_ancestor = partition(head, prev, last);
    ListNode *pivot = (pivot_ancestor == NULL) ? head : pivot_ancestor->next;
    _quicksort(head, prev, pivot_ancestor);
    _quicksort(pivot->next, pivot, last);
  }
}

void quicksort(ListNode *head) {
  ListNode *last = get_last(head);
  _quicksort(head, NULL, last);
}

int main() {
  ListNode *head = NULL;

  // Creating head and assign 0.
  head = create_node(0);

  // Creating more 4 nodes. So we have 5 in total.
  append_nodes(head, 4);

  // Add element with value 10 at the beginning of the list.
  push(&head, 10);

  // Add element with value 11 after 10.
  insert_after(head, 11);
  
  print_list(head);

  cout << "\nSort list and print.\n";
  quicksort(head);
  print_list(head);

  free_list(head);

  return 0;
}
