/**
 * You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of
 * f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|,
 * where |x| denotes absolute value of x.
 * 
 * Example:
 * Given A = [1, 3, -1]
 *
 * f(1, 1) = f(2, 2) = f(3, 3) = 0
 * f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
 * f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
 * f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5
 * So, we return 5.
 *
 * Time complexity: O(N), where N is the size of the array.
 * Space complexity: O(1).
 *
 * Explanation: My solution is different from the editorial, but has better
 * space complexity. Think about what you are calculating with each of these
 * absolute values in the equation. Each of these values is a distance between
 * two integer numbers. So, if we are able to add the distance |i - j| to the
 * other distance |A - B| we can get an equation that we can solve in O(N) time.
 * Think about these integers in the x-axis:
 * x: ... -4  -3  -2  -1  0  1  2  3  4 ...
 * |i - j| will always be a positive value, which means it will always increase
 * the distance between the integer numbers A and B. So, we have two options:
 * or we add our |i - j| distance to max(A, B) sending our right x-value more
 * to the right of the x-axis or we subtract the distance |i - j| from min(A, B)
 * sending our left x-value more to the left of the x-axis. Lets define our new
 * equation as |C - D|, where C = max(A, B) + |i - j| and D = min(A, B). Notice,
 * that we maximize |C - D| by making C the biggest possible value and D the
 * minimum. If we start from the end of our array we can easily find the maximum
 * C value. For a given i the maximum value C can increase by 1 because i is one
 * unit further than it was before in the previous iteration, or C can become
 * a[i], because the current value a[i] is the biggest value found until now.
 * We make D the current value a[i] and store in our answer max(ans, C - D).
 * For example,
 *        0  1   2   3  4
 * Given -3, 6, -2, -1, 2
 * i = 4 .. 0
 * C = 2 (a[4] + 0), 3 (max + 1), 4 (max + 1), 6 (a[1] + 0), 7 (max + 1)
 * D = 2,           -1,          -2,           6,           -3
 * ans = 0, 4, 6, 6, 10
 * 
 * i = 0 .. 4 (see why we are going also from 0 .. 4 below)
 * C = -3 (a[0] + 0), 6 (a[1] + 0), 7 (max + 1), 8 (max + 2), 9 (max + 3)
 * D = -3,            6,           -2,          -1,           2
 * ans = 10 10 10 10 10
 * So, we return 10
 *
 * Notice, we are going from the end of the array to the beginning and this is
 * fine as long as the final minimum value D is at the left of the maximum value
 * in the array. Otherwise, when we found the maximum value C, the minimum value
 * D that would give our answer already passed in our iterations because it was
 * at the right of this final C value. To solve this problem we need to iterate
 * from the beginning of the array to, so we can check for our C value the
 * minimum values that are at its right.
 */

#include <iostream>
#include <vector>

using namespace std;

int maxArr(vector<int> &a) {
  if (a.size() == 0) return 0;

  int ans = INT_MIN, mx = INT_MIN;

  for (int i = a.size() - 1; i >= 0; i--) {
    mx = max(a[i], mx + 1);
    ans = max(ans, mx - a[i]);
  }

  mx = INT_MIN;

  for (int i = 0; i < a.size(); i++) {
    mx = max(a[i], mx + 1);
    ans = max(ans, mx - a[i]);
  }

  return ans;
}

int main() {
  // vector<int> a = {};
  // vector<int> a = {1};
  // vector<int> a = {1, 0};
  // vector<int> a = {0, 1};
  // vector<int> a = {1, 1, 1};
  // vector<int> a = {1, 3, -1};
  // vector<int> a = {-3, 6, -2, -1, 2};
  // vector<int> a = {-1, 3, -2, -3, 5};
  // vector<int> a = {-1, 0, -1, -4, 6, -3, 8, 2, 3, 10, 6};
  vector<int> a = {-2, 3, 4, 5, 2, 4, 2, 7, 4, -2, -6, 2, 5, 8, 1, 3, -2};

  int m = maxArr(a);

  cout << "m: " << m << endl;

  return 0;
}