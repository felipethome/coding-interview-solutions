/**
 * Implement pow(x, n) % d. In other words, given x, n and d, find (x^n % d)
 * 
 * Note that remainders on division cannot be negative so make sure the answer
 * you return is non negative.
 *
 * Example:
 * 
 * Given, x = 2, n = 3, d = 3
 * Output 2, because 2^3 % 3 = 8 % 3 = 2.
 *
 * Time complexity: O(logN), where N is the exponent.
 * Space complexity: O(1).
 *
 * Explanation: to understand this problem you need to think about the binary
 * form of the exponent. For example, the binary form of 200 is: 11001000,
 * which is 128 + 64 + 8. So, if our base is 2 (it could be any other integer),
 * then 2^200 = 2^128 * 2^64 * 2^8
 * Now, notice that
 * 2^2 = 2 * 2 = 4
 * 2^4 = 4 * 4 = 16
 * 2^8 = 16 * 16 = 256
 * So, we can reuse the previous result to get the next result when our exponent
 * is a power of 2 (2, 4, 8, ...).
 *
 * To solve this exercise we just want to look at the binary form of our
 * exponent and check which bits are 1. When the bit is 0 we just update a
 * variable "curr" to be our base to the power of the current binary position.
 * When the bit is 1 it means we need to include in our answer "curr", so we
 * multiply "curr" by the answer we have so far.
 * 
 * In our example, we would eventually get 2^8 and we would check that the bit
 * for 8 is 1 so we would include in our answer 2^8. After some more iterations
 * we would have 2^64 and we would check that the bit for 64 is 1 in our
 * exponent so we would include 2^64 in our answer that currently is 2^8, so we
 * would get
 * ans = 2^8 * 2^64 =>
 * ans = ans * curr = 2^72
 * We would do the same thing for 2^128 and finally get
 * ans = 2^72 * 2^128 =>
 * ans = ans * curr = 2^200
 *
 * Of course, this algorithm works for any base and any positive exponent.
 */

#include <iostream>
#include <vector>

using namespace std;

int pow(int x, int n, int d) {
  int base = x, ans = 1;

  while (n > 0) {
    // Check if the last bit is 1, which means we need to include in our answer
    // the base^(current binary power).
    if (n & 1) {
      ans = (ans * base) % d;
      n--;
    }
    // If it is not 1 we just update our base to the next binary power
    // base^(binary power), which is current base * current base.
    else {
      base = (base * base) % d;
      n = n >> 1;
    }
  }

  if (ans < 0) return (ans + d) % d;
  return ans;
}

int main() {
  cout << pow(2, 11, 5000) << endl;

  return 0;
}