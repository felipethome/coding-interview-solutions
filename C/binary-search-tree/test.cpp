#include <iostream>
#include <queue>

#include "bst.h"

using namespace std;

int main() {
  TreeNode *root = NULL;

  insert(&root, 12);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 1);
  insert(&root, 9);

  // int number;

  // // Test search.
  // cout << "Enter number to be searched: ";
  // cin >> number;
  // cout << endl;

  // if (search(root, number)) cout << "Found" << endl;
  // else cout << "Not found" << endl;

  // // Test deletion.
  // cout << "Enter number to be deleted: ";
  // cin >> number;
  // cout << endl;

  // cout << "Before deletion the number was: ";
  // if (search(root, number)) cout << "Found" << endl;
  // else cout << "Not found" << endl;

  // remove(&root, number);

  // cout << "After deletion the number was: ";
  // if (search(root, number)) cout << "Found" << endl;
  // else cout << "Not found" << endl;

  // Test traversal
  cout << "Inorder traversal:" << endl;
  inorder(root);

  return 0;
}