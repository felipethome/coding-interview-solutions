/**
 * You are given a set of coins S. In how many ways can you make sum N assuming
 * you have infinite amount of each coin in the set.
 * 
 * Note : Coins in set S will be unique. Expected space complexity of this
 * problem is O(N).
 *
 * Time complexity: O(N * size of S).
 * Space complexity: O(N).
 *
 * Explanation: we need two loops. One to go coin by coin and another one to
 * ivestigate all the sums from 0..N. Our base case is the sum 0, where we
 * always have one way of doing it and it is by picking no coin.
 * So, we create an array of size N + 1 (the +1 is to accomodate our base case).
 * Then, we start with the first coin and for each possible sum we check in
 * our array the element a[currentSum - currentCoin], where currentSum is the
 * current sum we are looking at in our loop. The number of ways of doing this
 * currentSum will be the already stored value in this currentSum that is
 * a[currentSum], plus the value at a[currentSum - currentCoin] indicating the
 * number of ways we can make the sum "currentSum - currentCoin".
 *
 * Example:
 * S = [1, 2, 3]
 * N = 4
 *
 * indices/sums: 0 1 2 3 4
 * initial   a = 1 0 0 0 0
 * coin 1    a = 1 1 1 1 1
 * coin 2    a = 1 1 2 2 3
 * coin 3    a = 1 1 1 3 4
 *
 * Our answer is the last element of this array, that is 4.
 */

#include <iostream>
#include <vector>

using namespace std;

int coinchange(vector<int> &s, int n) {
  if (s.size() == 0 || n == 0) return 1;

  vector<int> ans(n + 1, 0);

  ans[0] = 1;

  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j < ans.size(); j++) {
      if (j < s[i]) continue;
      ans[j] = (ans[j] + ans[j - s[i]]) % 1000007;
    }
  }

  return ans[ans.size() - 1];
}

int main() {
  vector<int> s = {1, 2, 3};
  int n = 4;

  int ms = coinchange(s, n);

  cout << "max sum: " << ms << endl;

  return 0;
}