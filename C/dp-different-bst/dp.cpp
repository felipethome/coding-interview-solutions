/**
 * Given N, how many structurally unique BST’s (binary search trees) that store
 * values 1...N?
 * 
 * Example:
 * Given N = 3, there are a total of 5 unique BST’s.
 * 
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 * Time complexity: O(N^2), where N is the given number.
 * Space complexity: O(N).
 *
 * Explanation: we start from the base case where N = 1, and the number of
 * different BST’s is one. Give N bigger than 1 we need to calculate all the
 * answers for i < N, so we can finally calculate N. Notice that at a given
 * node value i, this node can assume all positions in the tree. So, when our
 * current node i is at position j, we want to check how many different BST’s
 * we have above i at position j, and how many we have under i at position j.
 * We multiply these two number of possibilities to find the total number of
 * combinations. We then accumulate the result for all positions j < i.
 *
 * This exercise has the same approach as the exercise "Number of chords in a
 * circle that don't intersect", including the same results:
 * for N: 1  2  3   4   5 ...
 * ways:  1  2  5  14  42 ...
 */

#include <iostream>
#include <vector>
#include <map>
#include <sys/time.h>
#include <ctime>

using namespace std;

int numTrees(int n) {
  if (n <= 0) return 0;

  vector<int> ans;
  ans.push_back(1);
  ans.push_back(1);

  for (int i = 2; i <= n; i++) {
    int sum = 0;
    for (int j = 0; j < i; j++) {
      sum += (ans[j] * ans[i - 1 - j]);
    }
    ans.push_back(sum);
  }

  return ans.back();
}

static uint64_t now() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return ((uint64_t) t.tv_sec) * 1000000 + (uint64_t) t.tv_usec;
}

int main() {
  vector<int> tests;

  tests.push_back(0); // 0
  tests.push_back(1); // 1
  tests.push_back(2); // 2
  tests.push_back(3); // 5
  tests.push_back(4); // 14
  tests.push_back(5); // 42
  tests.push_back(6); // 132
  tests.push_back(7); // 429

  for (int i = 0; i < tests.size(); i++) {
    int input = tests[i];

    uint64_t t1 = now();
    int m = numTrees(input);
    uint64_t t2 = now();

    cout << "answer: " << m << " time: " << t2 - t1 << "usec" << endl;
  }

  return 0;
}