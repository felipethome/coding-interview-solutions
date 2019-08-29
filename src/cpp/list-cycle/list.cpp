/*
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 * Example:
 *                 ______
 *                |     |
 *                \/    |
 *       1 -> 2 -> 3 -> 4
 *
 * Return 3
 *
 * Time complexity: O(N), where N is the size of the list.
 *
 * Explanation: My first approach was to create a dummy node and make the "next"
 * pointers of the nodes I already visited point to this dummy node. This solves
 * the question and it is really easy to think about, but probably the
 * interviewer would not like this since I'm destroying the data structure.
 * The right approach is to use the Floyd's Cycle Finding Algorithm.
 * In this algorithm we have two pointers: a hare, and a turtoise. The hare,
 * walks at two times the speed of the turtoise. When there is a cycle
 * eventualy they will meet (and if they do not meet before the last point of
 * the list there is no cycle). Now, that we know if there is a cycle we need to
 * find the start node. To do that we can:
 * 
 * 1. Find out the size of the loop walking with one of your pointers until you
 * meet the other one again, call this size (distance) k. Now put a pointer at
 * the head of the list and another one k nodes distant. Walk with them one node
 * at a time and when they meet you have the start node.
 *
 * 2. This another approach inveolves more math and it is less intuitive, but
 * once revealled it is really easy to implement. Let's see the math:
 * c = distance from list's head to to cycle's start node.
 * L = length of the loop
 * k = distance from meeting point to the cycle's start node.
 * t = number of times the turtoise ran in loop before meeting with the hare.
 * h = number of times the hare ran in loop before meeting with the turtoise.
 * 
 * Number of steps travelled by the turtoise:
 * s = c + tL + k
 * Number of steps travelled by the hare:
 * 2s = c + hL + k
 * Solving to L:
 * L = (c + k) / (h - 2t) or
 * c + k = (h - 2t)L
 *
 * So c + k is a multiple of L. Let's suppose h - 2t = 1, then: c = L - k.
 * Let's suppose h - 2t = 2, then: c = 2L - k. Now with 3, then 4, etc.
 * It turns out 2L, 3L, 4L are equivalent to L. Conclusion: use a pointer at
 * the list's head and another in the meeting node. Walk with them one node at a
 * time and when they meet you have the start node.
 *          
 *                      c
 *                   _______
 *                  |       |
 *             0 -> 0 -> -> 0 -> 0
 *                          |    |
 *                 L - k    0    0
 *                          |    |
 *        meeting node ---> 0 <- 0
 *
 * It is difficult to draw L - k, but it is the two nodes from the metting node
 * to the cycle's start node.
 *
 * See in the draw above how L - k = 2 nodes, and c = 2 nodes.
 */

#include <iostream>

#include "../linked-list/list.h"

using namespace std;

ListNode* detectCycle(ListNode* a) {
  if (a == NULL || a->next == NULL) return a;

  ListNode *t1 = a, *t2 = a, *h = a;

  do {
    t1 = t1->next;
    if (h->next) h = h->next->next;
  } while (h != NULL && h->next != NULL && h != t1);

  if (h && h->next) {
    while (t2 != t1) {
      t1 = t1->next;
      t2 = t2->next;
    }

    return t2;
  }

  return NULL;
}

// ListNode* detectCycle(ListNode* a) {
//   ListNode *cn = a, *pn = NULL, *nn = NULL;
//   ListNode *dummy = new ListNode(0);

//   while (cn != NULL && cn != dummy) {
//     nn = cn->next;
//     cn->next = dummy;
//     pn = cn;
//     cn = nn;
//   }


//   if (cn == NULL) {
//     cout << "no cycle" << '\n';
//     return NULL;
//   }
//   else {
//     cout << "pn: " << pn->val << '\n';
//     return pn;
//   }
// }

int main() {
  ListNode *head = NULL, *r = NULL;

  cout << "Creating...\n";
  head = create_node(1);
  append(head, 2);
  append(head, 3);
  append(head, 4);

  print_list(head);

  ListNode *last = get_last(head);
  ListNode *a = head->next->next;

  last->next = a;

  r = detectCycle(head);
  cout << "\nAnswer:\n";
  print_node(r, '\n');

  return 0;
}
