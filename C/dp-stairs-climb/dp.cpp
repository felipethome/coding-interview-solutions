/**
 * You are climbing a stair case. It takes N steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Example:
 * Given 3
 * Return 3. Because the steps would be: [1 1 1], [1 2], [2 1].
 *
 * Time complexity: O(N), where N is the number of steps.
 * Space complexity: O(1) if optimized since this is just Fibonacci in the end.
 *
 * Explanation: each time you can do two things: climb 1 step or climb two. So,
 * you need to check the two possibilities. The number of ways for a given N, is
 * the number of ways for N - 1 plus the number of ways for N - 2. Since, we
 * can take 1 or two steps we have the initial conditions:
 * N = 0 => 1
 * N = 1 => 1
 * And because of that our answer is just a Fibonacci number.
 *
 * For example,
 * indices: 0 1 2 3
 * answer:  1 1 2 3
 *
 * answer[3] = answer[1] + answer[2].
 */

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
  vector<int> ans(n + 1, 0);

  ans[0] = 1;
  ans[1] = 1;

  // The answer will always be a Fibonacci number (1, 1, 2, 3, 5, 8, ...). So,
  // you can optimize the space complexity to O(1).
  for (int i = 2; i < ans.size(); i++) {
    ans[i] = ans[i - 1] + ans[i - 2];
  }

  return ans[ans.size() - 1];
}

int main() {
  int n = 4;

  int m = climbStairs(n);

  cout << "max ways: " << m << endl;

  return 0;
}