/**
 * You are given the following:
 * A positive number N
 * Heights: A list of heights of N persons standing in a queue
 * Infronts: A list of numbers corresponding to each person (P) that gives the
 * number of persons who are taller than P and standing in front of P
 * 
 * You need to return list of actual order of persons’s height
 * 
 * Note: consider that heights will be unique.
 *
 * Time complexity:
 *
 * Explanation: what is the place for the smallest person in the queue? To find
 * that we just need to count the number of people in front of him starting at
 * the very beginning of the array. And for the second smallest person? Again,
 * it is the number of people in front of him counted from the very beginning
 * of the array, but this time we need to realize that we should just count free
 * spots remaining in our answer. So if in our count we fall into a position
 * where the first smallest person was placed we don't take it into account.
 *
 * Based on that, we just need to sort our array of heights and do the process
 * described above. The sorting process give us a O(logN) time complexity,
 * where N is the number of elements in the array.
 *
 * Now, can we do something to improve our code? Yes, we can. When we are
 * counting free spots to find out where our element should be placed in our
 * answer we take O(N) time, but if we use a segment tree we can find this spot
 * in O(logN) time. So, that is what we do. We build a segment tree with
 * information about free spots in our answer.
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPowerOfTwo(int n) {
  return (n & (n - 1)) == 0;
}

// Build the segment tree that contains the amount of free spaces in our
// answer vector.
void buildTree(vector<int> &tree, int treeSize, int initialValue) {
  int value = initialValue, rest;
  
  tree.push_back(value);

  // Build tree top down.
  for (int i = 0; i < (treeSize / 2); i++) {
    // This rest variable is here in case the number is odd because then one
    // of our branches needs to contain one more space. In this code I chose
    // the left branch to have this extra space.
    rest = (tree[i] % 2) && tree[i] > 1 ? 1 : 0;
    value = tree[i] / 2;
    tree.push_back(value + rest);
    tree.push_back(value);
  }
}

int getIndex(vector<int> &tree, int infront, int i, int s, int e) {
  // Depending on your input you would need to check if the place you are is
  // valid (there is one empty space) with "if (tree[i] == 1)".
  if (s == e) {
    tree[i] = 0;
    return s;
  }

  // In top down approach decrement the amount of free spaces. If the tree
  // becomes invalid and this function return -1 we should exit the program,
  // that is why we can go top down.
  tree[i]--;

  int mid = (s + e) / 2;

  // Check if the left branch has enough free spaces.
  if (tree[2 * i + 1] > infront) {
    return getIndex(tree, infront, 2 * i + 1, s, mid);
  }
  else {
    // When going to the right branch we need to subtract from our infront
    // value the amount of free spaces we have in the left branch.
    return getIndex(tree, infront - tree[2 * i + 1], 2 * i + 2, mid + 1, e);
  }
}

vector<int> orderPeople(vector<int> &heights, vector<int> &infronts) {
  vector<pair<int, int>> hi;
  vector<int> ans(heights.size(), -1), tree;
  int treeSize;

  // Build a vector with height and infront together (with height in the lead).
  for (int i = 0; i < heights.size(); i++) {
    hi.push_back(make_pair(heights[i], infronts[i]));
  }

  // Sort the vector by height.
  sort(hi.begin(), hi.end());

  // Our segment tree has size (nearestPowerOfTwo * 2) - 1. A segment tree is
  // always a complete binary tree, because it is stored in an array and to find
  // children of a give parent in an array we use formulas like 2i and 2i + 1.
  // If it wasn't a complete binary tree the formulas wouldn't work.
  if (!isPowerOfTwo(heights.size())) {
    int nextPowerOfTwo = pow(2, ceil(log((double)heights.size()) / log(2)));
    treeSize = (2 * nextPowerOfTwo) - 1;
  }
  else {
    treeSize = (2 * heights.size()) - 1;
  }

  buildTree(tree, treeSize, heights.size());

  for (int i = 0; i < hi.size(); i++) {
    int height = hi[i].first;
    int infront = hi[i].second;
    int idx = getIndex(tree, infront, 0, 0, hi.size() - 1);

    if (idx > -1) ans[idx] = height;
  }

  return ans;
}

int main() {
  vector<int> heights = {5, 3, 2, 6, 1, 4};
  vector<int> infronts = {0, 1, 2, 0, 3, 2};

  vector<int> r = orderPeople(heights, infronts);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}