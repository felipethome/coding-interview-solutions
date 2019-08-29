/*
 * Write a function that takes an unsigned integer and returns the number of 1
 * bits it has.
 *
 * Time complexity: O(N), where N is the number of bits.
 *
 * Explanation: You can AND the number with 1 and check the result. If is > 0
 * then increment a counter. at each iteration shift the number 1 bit to right.
 * Another solution, x & (x - 1) unset the lowest non-zero bit of a number,
 * because x - 1 is like x with the the lowest non-zero bit turned to 0 and
 * all the other ones before it turned to 1. So, while x is not zero increment
 * a counter.
 */

#include <stdio.h>

int numSetBits(unsigned int a) {
  unsigned int x = a;
  unsigned int c = 0;
    
  /*
   * x & (x - 1) unset the lowest non-zero bit.
   */
  do {
    x = x & (x - 1);
    c++;
  } while (x);
    
  return c;
}

// int numSetBits(unsigned int a) {
//   unsigned int x = a;
//   unsigned int c = 0;
    
//   while (x) {
//     if (x & 1) c++;
//     x = x >> 1;
//   }
    
//   return c;
// }

int main() {
  unsigned int count = numSetBits(5);

  printf("\n%u\n\n", count);

  return 0;
}