struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode **root, int val);
TreeNode* search(TreeNode *root, int val);
TreeNode* findMin(TreeNode *root);
TreeNode* findMax(TreeNode *root);
void remove(TreeNode **root, int val);
void levelorder(TreeNode *root);
void preorder(TreeNode *root);
void inorder(TreeNode *root);
void postorder(TreeNode *root);
int findHeight(TreeNode *root);