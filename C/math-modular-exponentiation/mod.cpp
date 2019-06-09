/*
 * Implement pow(a, b) % c recursively.
 *
 * Example:
 * Input : a = 2, b = 3, c = 3
 * Return : 2
 *
 * Time complexity: O(log n), where n is equal to the exponent.
 * Explanation: The entire problem is based on the fact that:
 * (x * y) % m = ((x % m) * (y % m)) % m
 * So, we can think in our exponention in terms of even and odd exponents.
 * If the exponent is even we have:
 * (a^(b / 2) % m) * (a^(b / 2) % m)
 * If the exponent is odd we have:
 * (a % m) * (a^(b - 1) % m)
 * And our base case is the exponent equal 0, in such case we return 1 % m.
 * Obs: notice, the % operator in C/C++ is actually the reminder operator and
 * not the modulo operator. They differ when applied to negative numbers. So,
 * the reminder operator can be turned into the modulo operator like this:
 * r = x % y, r < 0 ? r + y : r
 */

#include <iostream>

using namespace std;

long long int _mod(long long int a, int b) {
  long long int r = a % b;
  return r < 0 ? r + b : r;
}

int Mod(int a, int b, int c) {
  if (b == 0) return _mod(1, c);
  else if ((b % 2) == 0) {
    long long int y = Mod(a, b / 2, c);
    return _mod((y * y), c);
  }
  else {
    return _mod((_mod(a, c) * Mod(a, b - 1, c)), c);
  }
}

// long long int Mod(long long int x, long long int y, long long int p) {
//   long long int res = 1; // Initialize result

//   x = x % p; // Update x if it is more than or equal to p

//   while (y > 0) {
//     // If y is odd, multiply x with result
//     if (y & 1) res = _mod((res*x), p);

//     // y must be even now
//     y = y>>1; // y = y/2
//     x = _mod((x*x), p);  
//   }

//   return res;
// }

int main() {
  long long int r = Mod(71045970, 41535484, 64735492);
  // int r = Mod(2, 3, 3);

  cout << "Answer: " << r << '\n';

  return 0;
}