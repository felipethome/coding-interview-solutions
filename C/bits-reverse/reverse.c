/*
 * Reverse bits of an 32 bit unsigned integer.
 *
 * Example:
 * 00000000000000000000000000000011 =>
 * 11000000000000000000000000000000
 *
 * Time complexity: O(1). Or O(logN), if you want to consider the amount of bits
 * as a variable N.
 *
 * Explanation: divide and conquer approach:
 * 
 *              01101001
 *
 *             /        \
 *
 *           0110       1001
 *
 *          /   \       /   \
 *
 *        01    10    10    01
 *
 *        /\     /\    /\     /\
 *
 *       0  1   1  0  1  0   0  1
 *
 * Reverse the bottom bits with:
 * x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
 * then the bits in the previous level with:
 * ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
 * etc...
 */

#include <stdio.h>

unsigned int reverse(unsigned int a) {
  unsigned int x = a;
  
  x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
  x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
  x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
  x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
  x = (x << 16) | (x >> 16);
  
  return x;
}

// unsigned int reverse(unsigned int a) {
//   unsigned int d = a;
//   unsigned int b = 0;
//   unsigned int r = 0;
//   unsigned int p = 2147483648;
//   unsigned int c = 0;

//   while (c < 32) {
//       b = d % 2;
//       d = d / 2;
//       if (b) r += p;
//       p /= 2;
//       c++;
//   }
  
//   return r;
// }

int main() {
  unsigned int p = 3;
  unsigned int result = reverse(p);

  printf("\n%u\n\n", result);

  return 0;
}