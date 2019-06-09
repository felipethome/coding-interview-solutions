struct Node {
  int rank;
  int val;
  Node *parent;
  Node(int x, int y, Node *z) : rank(x), val(y), parent(z) {}
};

Node *makeSet(int val);

Node *findSetUtil(Node *n);

Node *findSet(int val);

void join(int val1, int val2);