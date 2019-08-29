/**
 * Given a set of digits (A) in sorted order, find how many numbers of length B
 * are possible whose value is less than number C.
 *
 * Notes:
 * 1. All numbers can only have digits from the given set. 
 * 
 * Constraints: 1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9
 * 
 * Example:
 *  Input:
 *    3 0 1 5  
 *    1  
 *    2  
 *  Output:  
 *    2 (0 and 1 are possible)  
 *
 *  Input:
 *    4 0 1 2 5  
 *    2  
 *    21  
 *  Output:
 *    5 (10, 11, 12, 15, 20 are possible)
 *
 * Time complexity: O(B), where B is the maximum number of digits. The size of
 * the array can be considered constant since will always be at most 10.
 * Space complexity: O(B), but the dynamic programming approach can be
 * optimized to O(1).
 *
 * Explanation: there are three cases:
 *
 * 1. B is larger than the number of digits in C. In such case we return 0.
 *
 * 2. B is smaller than the number of digits in C. In such case we return
 * n^b if we don't have a zero in the array, otherwise if B is larger than 1
 * then (n - 1) * n^(b - 1) because our possible numbers can't start with zero.
 * n is the size of the array A.
 *
 * 3. B is equal to the number of digits in C. In such case we need to count
 * the leaf nodes of our tree if possibilities. The tricky part is how to do
 * that without making mistakes.
 *
 * A tree looks like:
 * A = [1, 2]
 * B = 2
 * C = 22
 *
 *                      +----------+
 *           +----------+Empty root+---------+
 *           |          +----------+         |
 *           |                               |
 *           |                               |
 *        +--v--+                         +--v--+
 *        |     |                         |     |
 *    +---+  1  +--+                  +---+  2  |
 *    |   |     |  |                  |   |     |
 *    |   +-----+  |                  |   +-----+
 *    |            |                  |
 * +--v--+      +--v--+            +--v--+
 * |     |      |     |            |     |
 * |  1  |      |  2  |            |  1  |
 * |     |      |     |            |     |
 * +-----+      +-----+            +-----+
 *
 *
 * Let's define some things:
 * 
 * 1. First(i) is the number formed by the first i digits of C (where the first
 * digit is the one at the largest power (the one at the left)).
 *
 * 2. digit[i] is an array with the digit at position i of C (again, at
 * position 1 we have the digit with largest power of C).
 *
 * 3. lower[i] is an array where each element is the number of elements in array
 * A smaller than i. We fill this array for all the possible digits, so from
 * 0 to 9.
 *
 * 4. DP[i] is an array where each element denotes the total numbers of length
 * i which are less than first i digits of C. Initialized with zeros.
 *
 * Now, notice that DP[0] is always 0, and that we need to take care to not
 * take into account for DP[1] the number zero when B is larger than 1, because
 * number with more than one digit can't start with 0.
 *
 * DP[i] can be filled checking two cases:
 *
 * 1. For all the Numbers whose First(i - 1) is less than First(i - 1) of C,
 * we can put any digit at i’th index. Hence, DP[i] += (DP[i - 1] * n). Where
 * n is the size of A.
 * 
 * 2. For all the Numbers whose First(i - 1) is same as First(i - 1) of C, we
 * can only put those digits which are smaller than digit[i]. Hence,
 * DP[i] += lower[digit[i]].
 *
 * Case 1 we execute for every DP[i], but case 2 we just add if using the
 * numbers in the array we are able to make First(i - 1) of C.
 *
 * Notice, it is really easy to make this solution use O(1) space because
 * we just need the previous answer DP[i - 1] to make the next DP[i].
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(vector<int> &a, int b, int c) {
  if (a.size() == 0 || b <= 0 || c <= 0) return 0;

  int ans = 0, n = a.size(), len = 0;
  vector<int> digits;

  while (c > 0) {
    digits.insert(digits.begin(), c % 10);
    c /= 10;
    len++;
  }
  
  if (b > len) {
    return 0;
  }
  else if (b < len) {
    return a[0] == 0 && b > 1 ? (n - 1) * pow(n, b - 1) : pow(n, b);
  }
  else {
    int partialC = 0, partialV = 0;
    vector<int> dp(b + 1, 0), lower(10, 0);

    for (int i = 1, j = 0; i < lower.size(); i++) {
      while (j < a.size() && a[j] < i) j++;
      lower[i] = j;
    }

    for (int i = 1; i < dp.size(); i++) {
      dp[i] += (dp[i - 1] * n);
      if (partialV == partialC) dp[i] += lower[digits[i - 1]];
      if (i == 1 && a[0] == 0 && b > 1) dp[i] = max(dp[i] - 1, 0);

      partialC = partialC * 10 + digits[i - 1];
      for (int j = 0; j < a.size(); j++) {
        if (a[j] == digits[i - 1]) partialV = partialV * 10 + a[j];
      }
    }

    return dp[b];
  }

  return ans;
}

// My original solution fixed and working. It is basically the same thing as
// the editorial solution.
// int solve(vector<int> &a, int b, int c) {
//   if (a.size() == 0 || b <= 0 || c <= 0) return 0;

//   int ans = 0, n = a.size(), len = 0, rev = 0;

//   while (c > 0) {
//     len++;
//     rev = (rev * 10) + (c % 10);
//     c /= 10;
//   }
  
//   if (b > len) {
//     ans = 0;
//   }
//   else if (b < len) {
//     ans = a[0] == 0 && b > 1 ? (n - 1) * pow(n, b - 1) : pow(n, b);
//   }
//   else {
//     int partialC = 0, partialV = 0;

//     for (int i = 0; i < len; i++) {
//       int digit = rev % 10;
//       rev /= 10;

//       ans = ans * n;

//       int firstSmall = 0;
//       for (int j = 0; j < a.size() && a[j] < digit; j++) firstSmall++;

//       if (partialV == partialC) ans += firstSmall;

//       partialC = partialC * 10 + digit;
//       for (int j = 0; j < a.size(); j++) {
//         if (a[j] == digit) partialV = partialV * 10 + a[j];
//       }

//       if (i == 0 && a[0] == 0 && b > 1) ans = max(0, ans - 1);
//     }
//   }

//   return ans;
// }

int main() {
  vector<int> a = {0, 1, 2, 3};
  int b = 3;
  int c = 322;

  // vector<int> a = {0};
  // int b = 1;
  // int c = 1;

  // vector<int> a = {0, 1, 2, 5};
  // int b = 1;
  // int c = 2;
  
  // vector<int> a = {0, 1, 2, 5};
  // int b = 2;
  // int c = 21;

  // vector<int> a = {2};
  // int b = 5;
  // int c = 54167;

  // vector<int> a = {0, 1, 2, 5};
  // int b = 2;
  // int c = 8;
  
  // vector<int> a = {3, 4, 5, 6};
  // int b = 2;
  // int c = 42;
  
  // vector<int> a = {0, 1, 2, 3};
  // int b = 3;
  // int c = 320;
  
  // vector<int> a = {0, 1, 2, 3};
  // int b = 3;
  // int c = 300;

  // // vector<int> a = {1, 3};
  // int b = 2;
  // int c = 34;
  
  // vector<int> a = {1, 3};
  // int b = 2;
  // int c = 12;

  // vector<int> a = {2, 9};
  // int b = 5;
  // int c = 17015;
  
  // vector<int> a = {2, 3, 5, 6, 7, 9};
  // int b = 5;
  // int c = 42950;
  
  // vector<int> a = {3, 4, 7};
  // int b = 5;
  // int c = 71007;
  
  // vector<int> a = {0, 1, 2, 3, 4, 5, 7, 8, 9};
  // int b = 5;
  // int c = 14732;

  int r = solve(a, b, c);

  cout << r << endl;

  return 0;
}