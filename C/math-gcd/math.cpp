/**
 * Given 2 non negative integers m and n, find gcd(m, n)
 * 
 * GCD of 2 integers m and n is defined as the greatest integer g such that g
 * is a divisor of both m and n. Both m and n fit in a 32 bit signed integer.
 *
 * Example:
 * m = 6
 * n = 9
 * Return 3.
 *
 * Time complexity: O(M + N), where M and N are the inputs.
 * Space complexity: O(1), if not using recursion.
 *
 * Explanation: Euclidian's Algorithm. Keep doing the mod operation until the
 * smaller value is 0. For example,
 *
 * 1112 mod 695 = 417
 * 695 mod 417 = 278
 * 417 mod 278 = 139
 * 278 mod 139 = 0
 * So we return 139.
 */

#include <iostream>

using namespace std;

int gcd(int m, int n) {
  if (m < n) {
    int temp = m;
    m = n;
    n = temp;
  }

  if (n == 0) return m;
  return gcd(m % n, n);
}

int main() {
  int a = 1112, b = 695;

  int r = gcd(a, b);

  cout << r << endl;

  return 0;
}