/*
 * Impementation of an AVL tree.
 */

#include <iostream>
#include <queue>

#include "avl.h"

using namespace std;

int height(BstNode *node) {
  if (node == NULL) return -1;
  return node->height;
}

void rotateClockwise(BstNode **root) {
  BstNode *newRoot = (*root)->left;
  (*root)->left = newRoot->right;
  newRoot->right = (*root);

  (*root)->height = 1 + max(height((*root)->left), height((*root)->right));
  newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

  *root = newRoot;
}

void rotateCounterClockwise(BstNode **root) {
  BstNode *newRoot = (*root)->right;
  (*root)->right = newRoot->left;
  newRoot->left = (*root);

  (*root)->height = 1 + max(height((*root)->left), height((*root)->right));
  newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
  
  *root = newRoot;
}

void insert(BstNode **root, int data) {
  if (*root == NULL) {
    BstNode *n = new BstNode(data);
    *root = n;
  }
  else if (data <= (*root)->data) {
    insert(&((*root)->left), data);
  }
  else {
    insert(&((*root)->right), data);
  }

  int balance = height((*root)->left) - height((*root)->right);

  if (balance > 1) {
    // LL
    if (height((*root)->left->left) >= height((*root)->left->right)) {
      rotateClockwise(root);
    }
    // LR
    else {
      rotateCounterClockwise(&((*root)->left));
      rotateClockwise(root);
    }
  }
  else if (balance < -1) {
    // RR
    if (height((*root)->right->right) >= height((*root)->right->left)) {
      rotateCounterClockwise(root);
    }
    // RL
    else {
      rotateClockwise(&((*root)->right));
      rotateCounterClockwise(root);
    }
  }
  else {
    (*root)->height = 1 + max(height((*root)->left), height((*root)->right));
  }
}

BstNode* findMin(BstNode *root) {
  if (root->left == NULL) return root;
  else return findMin(root->left);
}

BstNode* findMax(BstNode *root) {
  if (root->right == NULL) return root;
  else return findMin(root->right);
}

void remove(BstNode **root, int data) {
  if (*root == NULL) return;
  else if (data < (*root)->data) remove(&((*root)->left), data);
  else if (data > (*root)->data) remove(&((*root)->right), data);
  else {
    if ((*root)->left == NULL && (*root)->right == NULL) {
      delete *root;
      *root = NULL;
    }
    else if ((*root)->left == NULL) {
      BstNode *temp = *root;
      *root = (*root)->right;
      delete temp;
    }
    else if ((*root)->right == NULL) {
      BstNode *temp = *root;
      *root = (*root)->left;
      delete temp;
    }
    else {
      BstNode *min = findMin((*root)->right);
      (*root)->data = min->data;
      remove(&((*root)->right), min->data);
    }
  }

  if (*root == NULL) return;

  int balance = height((*root)->left) - height((*root)->right);

  if (balance > 1) {
    // LL
    if (height((*root)->left->left) >= height((*root)->left->right)) {
      rotateClockwise(root);
    }
    // LR
    else {
      rotateCounterClockwise(&((*root)->left));
      rotateClockwise(root);
    }
  }
  else if (balance < -1) {
    // RR
    if (height((*root)->right->right) >= height((*root)->right->left)) {
      rotateCounterClockwise(root);
    }
    // RL
    else {
      rotateClockwise(&((*root)->right));
      rotateCounterClockwise(root);
    }
  }
  else {
    (*root)->height = 1 + max(height((*root)->left), height((*root)->right));
  }
}

BstNode* search(BstNode *root, int data) {
  if (root == NULL) return NULL;
  else if (root->data == data) return root;
  else if (data <= root->data) return search(root->left, data);
  else return search(root->right, data);
}

void levelorder(BstNode *root) {
  if (root == NULL) return;
  queue<BstNode *> q;
  q.push(root);

  while (!q.empty()) {
    BstNode *t = q.front();
    cout << t->data << " ";
    if (t->left != NULL) q.push(t->left);
    if (t->right != NULL) q.push(t->right);
    q.pop();
  }
}

void inorder(BstNode *root) {
  if (root == NULL) return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}