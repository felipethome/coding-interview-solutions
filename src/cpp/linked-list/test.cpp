#include <iostream>
#include <stdlib.h>

#include "list.h"

using namespace std;

int main() {
  Node *tmp = NULL, *head = NULL;

  cout << "\nCreating head and assign 0.\n";
  head = create_node(0);

  cout << "\nCreating more nine nodes. So we have 10 in total.\n";
  append_nodes(head, 9);

  cout << "\nPrint all elements.\n";
  print_list(head);

  cout << "\nRetrieve the third node (that has value 2).\n";
  tmp = get_node(head, 2);
  if (tmp != NULL) {
    cout << "Retrieved. ";
    print_node(tmp, '\n');
  }
  else {
    cout << "Not found.\n";
  }

  cout << "\nRemove the third node and print (that has value 2).\n";
  remove_node(&head, tmp);
  print_list(head);

  cout << "\nRemove the first node and print (that has value 0).\n";
  remove_node(&head, head);
  print_list(head);

  cout << "\nRetrieve the last node (that has value 9).\n";
  tmp = get_node(head, 7);
  if (tmp != NULL) {
    cout << "Retrieved. ";
    print_node(tmp, '\n');
  }
  else {
    cout << "Not found.\n";
  }

  cout << "\nRemove the last node and print (that has value 9).\n";
  remove_node(&head, tmp);
  print_list(head);

  cout << "\nAdd element with value 10 at the beginning of the list.\n";
  push(&head, 10);
  print_list(head);

  cout << "\nAdd element with value 11 after 10.\n";
  insert_after(head, 11);
  print_list(head);

  free_list(head);

  return 0;
}
