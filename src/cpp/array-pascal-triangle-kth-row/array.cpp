/**
 * Given an index k, return the kth row of the Pascal’s triangle.
 * Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1]
 * from previous row R - 1.
 * 
 * Note: k is 0 based. k = 0, corresponds to the row [1]. 
 * 
 * Can you optimize your algorithm to use only O(k) extra space?
 *
 * Example:
 * 
 * k = 3
 * Output [1, 3, 3, 1]
 *
 * Time complexity: O(K), where K is the row number.
 * Space complexity: O(K).
 *
 * Explanation: forget the editorial tip. The best way to calculate this is
 * using a recurrence relation. So, you can make this in linear time.
 *
 * (n, k) represents Newton's binomial.
 *
 * (n, k) = n! / (n - k)!k!
 *
 * For k = 1
 * n! / (n - 1)!1! =
 * = n * (n - 1)! / (n - 1)! =
 * = n
 * 
 * For k = 2
 * n! / (n - 2)!2! =
 * = n * (n - 1) * (n - 2)! / (n - 2)!2 =
 * = n * (n - 1) / 2
 *
 * For k = 3
 * n! / (n - 3)!3! =
 * = n * (n - 1) * (n - 2) * (n - 3)! / (n - 3)!3! =
 * = n * (n - 1) * (n - 2) / 3 * 2
 *
 * So for a row n, its n + 1 elements xi can be computed like:
 *
 * x0 = 1
 * x1 = x0 * n
 * x2 = x1 * (n - 1) / 2
 * x3 = x2 * (n - 2) / 3
 * x4 = x3 * (n - 3) / 4
 * x5 = x4 * (n - 4) / 5
 * ...
 * xn = xn-1 * (n - (n - 1)) / n
 *
 * Notice there is another optimization you could make that is you could
 * calculate just the first n / 2 elements of the row and the other ones
 * are symmetric.
 * 
 * Editorial:
 * Create a vector with k + 1 positions, all filled with 1. Iterate
 * from 2 to k, including k (start at 2 because row 0 and 1 are [1] and [1, 1],
 * respectively). Start to calculate the new numbers from the end of the new
 * line because we don't want to use extra space. So for any element we perform
 * ans[j] = ans[j] + ans[j - 1]. Calculating from the beginning wouldn't work
 * because we would have modified numbers in our answer that we would need to
 * calculate the next number.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int a) {
  vector<int> ans(a + 1);
  int prev = 1;

  for(int i = 0; i <= a; i++){
    ans[i] = prev;
    prev = prev * (a - i) / (i + 1);
  }

  return ans;
}

// vector<int> getRow(int k) {
//   vector<int> ans(k + 1, 1);
  
//   for (int i = 2; i <= k; i++) {
//     for (int j = i - 1; j > 0; j--) {
//       ans[j] = ans[j] + ans[j - 1];
//     }
//   }
  
//   return ans;
// }

int main() {
  int a = 4;

  vector<int> r = getRow(a);

  cout << endl;
  for (int e : r) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}