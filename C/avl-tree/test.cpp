#include <iostream>
#include <queue>

#include "avl.h"

using namespace std;

int main () {
  BstNode *root = NULL;

  insert(&root, 1);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 6);
  insert(&root, 5);
  insert(&root, -2);
  insert(&root, -5);
  insert(&root, -8);

  int number;

  // // Test insertion and search.
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
  cout << endl;

  cout << "Level order traversal:" << endl;
  levelorder(root);
  cout << endl;

  return 0;
}