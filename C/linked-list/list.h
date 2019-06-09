struct ListNode {
  struct ListNode* next;
  int val;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 * Get the middle element of the list.
 */
ListNode* get_middle(ListNode *head);
/*
 * Get the last element of the list.
 */
ListNode* get_last(ListNode *head);
/*
 * Create a node with the specified value.
 */
ListNode* create_node(int val);
/*
 * Add a node at the end of the list.
 */
void append(ListNode *head, int val);
/*
 * Add a node at the beginning of the list.
 */
void push(ListNode **head, int val);
/*
 * Insert node after previous_node
 */
void insert_after(ListNode *previous_node, int val);
/*
 * Remove the node.
 */
int remove_node(ListNode **head, ListNode *node);
/*
 * Free memory used by the list.
 */
void free_list(ListNode *head);

/* --- Helper functions ---- */

/*
 * Get the node in the n position (not with the value n).
 */
ListNode* get_node(ListNode *head, int n);
/*
 * Add n nodes at the end of the list with the current value of n the value of
 * the node.
 */
void append_nodes(ListNode *head, int n);
/*
 * Print a particular node followed by line_break.
 */
void print_node(ListNode *node, char line_break);
/*
 * Print the list.
 */
void print_list(ListNode *head);