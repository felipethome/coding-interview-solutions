/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 * A palindrome integer is an integer x for which reverse(x) = x where
 * reverse(x) is x with its digit reversed. Negative numbers are not
 * palindromic.
 * 
 * Example:
 * 
 * Given 12121
 * Output true
 * 
 * Given 123
 * Output false
 *
 * Time complexity: O(N), where N is the number of digits the input has.
 * Space complexity: O(1).
 *
 * Explanation: reserse the number and take care to not overflow. If the number
 * overflows or if the number is negative, so it is not a palindrome.
 */

#include <iostream>

using namespace std;

int reverse(int a) {
  int r = 0;

  while (a > 0) {
    int digit = a % 10;

    if (r > INT_MAX / 10 || r * 10 > INT_MAX - digit) return -1;

    r = r * 10 + digit;
    a /= 10;
  }

  return r;
}

bool isPalindrome(int a) {
  if (a < 0) return false;
  return reverse(a) == a;
}

int main() {
  // int a = 1231231233;
  int a = 12121;

  if (isPalindrome(a)) cout << a << " is palindrome." << endl;
  else cout << a << " is not palindrome." << endl;

  return 0;
}