/**
 * Merge k sorted linked lists and return it as one sorted list.
 *
 * Example:
 * 1 -> 10 -> 20
 * 4 -> 11 -> 13
 * 3 -> 8 -> 9
 *
 * Will result in:
 * 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
 *
 * Time complexity: O(N*logM), where N is the total numbers of nodes and M is
 * the number of lists.
 *
 * Explanation: organize the head nodes of the list in a min heap (
 * priority_queue with custom comparator in C++) and then start to create a new
 * list removing the root node and inserting the next node of the head you just
 * removed in the heap. Do that until you have no more nodes.
 */

#include <iostream>
#include <vector>
#include <queue>

#include "list.h"

using namespace std;

struct CompareNode {
  bool operator()(ListNode* const &p1, ListNode* const &p2) {
    return p1->val > p2->val;
  }
};

ListNode* mergeKLists(vector<ListNode*> &a) {
  ListNode *dummy = new ListNode(0);
  ListNode *tail = dummy;
  priority_queue<ListNode*, vector<ListNode*>, CompareNode> q;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != NULL) q.push(a[i]);
  }

  while (!q.empty()) {
    tail->next = q.top();
    q.pop();
    tail = tail->next;

    if (tail->next) {
      q.push(tail->next);
    }
  }

  return dummy->next;
}

ListNode* get_last(ListNode *head) {
  ListNode *curr = head;

  while (curr->next != NULL) {
    curr = curr->next;
  }

  return curr;
}

void append(ListNode *head, int val) {
  ListNode *last = get_last(head);
  ListNode *node = new ListNode(val);

  last->next = node;
}

int remove_node(ListNode **head, ListNode* node) {
  ListNode **curr = head;

  while (*curr != node && *curr != NULL) {
    curr = &((*curr)->next);
  }

  if (*curr == node) {
    *curr = node->next;
    free(node);
    return 1;
  }

  return 0;
}

void free_list(ListNode *head) {
  ListNode *curr = head, *tmp = NULL;

  while (curr != NULL) {
    tmp = curr;
    curr = curr->next;
    free(tmp);
  }
}

void print_node(ListNode *node, char separator) {
  cout << node->val << separator;
}

void print_list(ListNode *head) {
  ListNode *curr = head;

  while (curr != NULL) {
    print_node(curr, ' ');
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  ListNode *h1 = NULL, *h2 = NULL, *h3 = NULL, *r = NULL;

  h1 = new ListNode(3);
  h2 = new ListNode(2);
  h3 = new ListNode(1);

  append(h1, 6);
  append(h1, 9);
  append(h2, 5);
  append(h2, 8);
  append(h3, 4);
  append(h3, 7);

  vector<ListNode*> a = {h1, h2, h3};
  r = mergeKLists(a);

  print_list(r);

  return 0;
}