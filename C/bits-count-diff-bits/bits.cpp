/**
 * We define f(X, Y) as number of different corresponding bits in binary
 * representation of X and Y. For example, f(2, 7) = 2, since binary
 * representation of 2 and 7 are 010 and 111, respectively. The first and the
 * third bit differ, so f(2, 7) = 2.
 * 
 * You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of
 * f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer
 * modulo 10^9+7.
 *
 * Example:
 * A = [1, 3, 5]
 *
 * We return
 * f(1, 1) + f(1, 3) + f(1, 5) +
 * f(3, 1) + f(3, 3) + f(3, 5) +
 * f(5, 1) + f(5, 3) + f(5, 5) =
 * 
 * 0 + 1 + 1 +
 * 1 + 0 + 2 +
 * 1 + 2 + 0 = 8
 *
 * Time complexity: O(M * N), where N is the size of the given array and M the
 * number of bits. If you consider the number of bits a small constant so this
 * algorithm has linear time complexity.
 * Space complexity: O(1).
 *
 * Explanation: what this problem is asking is the sum of Hamming Distances.
 * 
 * Check one bit position at a time for each element. So we check
 * bit at position 1 for all elements, then bit at position 2 for all elements.
 * And for each of these bits we count how many of them are 1's and how many
 * are 0's, then the number of different bits for that position is
 * zeroBitCount * oneBitCount. For example:
 *
 * Given A = [1, 3, 5]
 * pos: 0 1 2
 *      -----
 *      0 0 1
 *      0 1 1
 *      1 0 1
 *
 * For position 0 we get 2 zeros and 1 one, so 2 * 1 different bits for
 * position 0. For position 1, 2 zeros and 1 one, so 2 * 1 different bits.
 * For position 2, 3 ones and 0 zeros, so 3 * 0 different bits. So, our answer
 * is (2 + 2 + 0) * 2 = 8. Notice we are multiplying by 2 because this exercise
 * considers f(X, Y) different of f(Y, X) though they are equal.
 */

#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007LL
#define INT_SIZE 32

int cntBits(vector<int> &a) {
  long long ans = 0;

  for (int i = INT_SIZE - 1; i >= 0; i--) {
    long long zeroCount = 0, oneCount = 0;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] & (1 << i)) oneCount++;
      else zeroCount++;
    }
    ans = (ans + zeroCount * oneCount) % MOD;
  }

  return (2LL * ans) % MOD;
}

// Naive O(N^2) time solution using XOR.
// int count1Bits(int n) {
//   int count = 0;

//   while (n) {
//     n = n & (n - 1);
//     count++;
//   }

//   return count;
// }

// int cntBits(vector<int> &a) {
//   int ans = 0;

//   for (int i = 0; i < a.size(); i++) {
//     for (int j = i; j < a.size(); j++) {
//       if (i == j) continue;
//       int bits = a[i] ^ a[j];
//       ans = (ans + 2 * count1Bits(bits)) % MOD;
//     }
//   }

//   return ans;
// }

int main() {
  // vector<int> a = {1, 3, 5};
  // vector<int> a = {2, 4, 6};
  // vector<int> a = {2, 7, 4, 3, 1};

  int r = cntBits(a);

  cout << r << endl;

  return 0;
}