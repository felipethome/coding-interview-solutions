/**
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum. For this problem, return the maximum sum.
 * 
 * Example:
 * 
 * Given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * Time complexity: O(N), where N is the size of the given array.
 * Space complexity: O(1).
 *
 * Explanation: the subarray with the maximum sum will never start with a
 * negative number, because you could discard this negative number and start
 * from the next position to make a larger sum. Also, every candidate sum will
 * always try to get as most positive sums as possible. For example, if you
 * have an array like [2, -1, 5] the maximum sum will be 2 + (-1) + 5, so even
 * if we have a negative number in the middle of our sum it is still better to
 * sum 5 with the sum (2 + (-1)) because its result is positive, so we get
 * 1 + 5 = 6. Thinking about all positive numbers in the array as possible
 * starting points for our maximum sum we will not consider the left part (all
 * the numbers to the left of the starting positive number) just if the sum of
 * the left part is negative.
 */

#include <iostream>
#include <vector>

using namespace std;

// Kadane's algorithm O(N).
int maxSubArray(vector<int> &a) {
  int sum = INT_MIN, acc = 0, i;

  for (i = 0; i < a.size(); i++) {
    // Don't let the subarray start with a negative number. Also, start the
    // sum again when it becomes negative.
    if ((acc + a[i]) > 0) {
      acc += a[i];
      sum = max(sum, acc);
    }
    else {
      acc = 0;
    }
    
    // In case there are just negative elements in the array.
    if (a[i] < 0 && a[i] > sum) sum = a[i];
  }

  return sum;
}

// // O(N^2).
// int maxSubArray(vector<int> &a) {
//   int sum = INT_MIN;

//   for (int i = 0; i < a.size(); i++) {
//     int acc = 0;
//     for (int j = i; j < a.size(); j++) {
//       acc += a[j];
//       sum = max(sum, acc);
//     }
//   }

//   return sum;
// }

int main() {
  vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  int r = maxSubArray(a);

  cout << r << endl;

  return 0;
}