/**
 * Divide two integers without using multiplication, division and mod operator.
 * Return the floor of the result of the division.
 *
 * Notes:
 * 1. Also, consider if there can be overflow cases. For overflow case,
 * return INT_MAX.
 *
 * Example:
 * 
 * 5 / 2 = 2
 *
 * Time complexity: O(K), where K is the number of bits, and can be considered
 * constant.
 * Space complexity: O(1).
 *
 * Explanation: the naive way is to keep subtracting the divisor from the
 * dividend until divided is smaller than divisor. But will have linear
 * time complexity to the dividend.
 *
 * The better way is to apply the same algorithm we use to divide base-10
 * numbers on the paper. We start from the end of the dividend and accumulate
 * the bits in a variable called currDividend until we get a number less
 * greater or equal to the divisor. At this moment we add the bit 1 to our
 * answer and update the currDividend to currDividend - divisor. For example,
 * lets see the division of 11 by 2 in decimal and binary bases:
 *
 * Decimal
 *
 * '
 * 11 | 2
 * ------
 * 1 is smaller than 2 so append 0 to the answer and keep going.
 *
 * ''
 * 11 | 2
 * ------
 * 11 is greater than 2 and we know 2 * 5 is the closest we can get to 11, so
 * append 5 to the answer and we are done because there are no other numbers.
 *
 * Binary
 *
 * '
 * 1011 | 0010
 * 1 is smaller than 2 so append 0 to the answer and keep going.
 * ans = 0
 *
 * ''
 * 1011 | 0010
 * 2 is equal to 2, so append 1 to the answer and 2 - 2 = 0 so make
 * currDividend = 0.
 * ans = 1
 *
 *   '
 * 1011 | 0010
 * 1 is smaller the 2 so append 0 to the answer and keep going.
 * ans = 10
 *
 *   ''
 * 1011 | 0010
 * 3 is larger then 2 so append 1 to the answer and make
 * currDividend = 3 - 2 = 1.
 * ans = 101
 *
 * Notice that in the decimal case we need to find out the number that is
 * closest to our currDividend because we have 9 options (1 to 9), but in the
 * binary case we just have one option (just 1).
 *
 * In our algorithm we need to perform this operations with positive numbers,
 * so get the absolute values of the input and keep the sign. Also, the
 * description of this problem is misleading because it states it wants the
 * Floor of the divisions, but Floor(-10 / 3) is -4 though the official
 * solution returns -3, so actually the problem wants the Ceil for negative
 * answer and the Floor for positive answer.
 *
 * Don't forget to check for overflows. Work with "long long" and after check
 * if the answer is larger or equal to abs(INT_MIN).
 */

#include <iostream>

using namespace std;

int divide(int a, int b) {
  if (b == 0) return INT_MAX;

  long long ans = 0, dividend = a, divisor = b, currDividend = 0;
  int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;

  dividend = abs(dividend), divisor = abs(divisor);

  for (long long i = 31; i >= 0; i--) {
    bool bit = dividend & (1LL << i);
    currDividend = (currDividend << 1LL) | bit;
    ans = ans << 1LL;

    if (currDividend >= divisor) {
      currDividend = currDividend - divisor;
      ans = ans | 1LL;
    }
  }

  ans = sign * ans;

  // This should be necessary to get a properly Floor as the exercise states,
  // but actually the official solution is looking for an algorithm that is
  // a Floor for positive answer, and Ceil for negative answer.
  // if (ans < 0 && currDividend != 0) ans--;

  return ans >= 2147483648 ? INT_MAX : ans;
}

// int divide(int dividend, int divisor) {
//   if (divisor == 0) return INT_MAX;
//   if (dividend == -2147483648 && divisor == -1) return INT_MAX;
//   if (dividend == -2147483648 && divisor == 1) return INT_MIN;

//   long long ans = 0, sign = 1;

//   if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
//     sign = -1;
//   }

//   long long a = abs((long long)dividend);
//   long long b = abs((long long)divisor);

//   while (a >= b) {
//     ans++;
//     a -= b;
//   }

//   return (int)(sign * ans);
// }

int main() {
  // int a = 5, b = 2;
  // int a = 11, b = 2;
  int a = 24, b = 4;
  // int a = 10, b = 3;
  // int a = 10, b = -3;
  // int a = -10, b = 3;
  // int a = -2147483648, b = -1;
  // int a = -2147483648, b = 1;

  int r = divide(a, b);

  cout << r << endl;

  return 0;
}