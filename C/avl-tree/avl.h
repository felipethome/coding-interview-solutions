struct BstNode {
  int data;
  BstNode *left;
  BstNode *right;
  int height;
  BstNode(int x) : data(x), left(NULL), right(NULL), height(0) {}
};

int height(BstNode *node);
void rotateClockwise(BstNode **root);
void rotateCounterClockwise(BstNode **root);
void insert(BstNode **root, int data);
BstNode* findMin(BstNode *root);
BstNode* findMax(BstNode *root);
void remove(BstNode **root, int data);
BstNode* search(BstNode *root, int data);
void levelorder(BstNode *root);
void inorder(BstNode *root);