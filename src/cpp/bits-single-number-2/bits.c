/*
 * Given an array of integers, every element appears thrice except for one which
 * occurs once. Find that element which does not appear thrice.
 * Note: Your algorithm should have a linear runtime complexity and not use
 * extra memory.
 *
 * Time complexity: O(N), where N is the number of bits.
 *
 * Explanation: for each number of the array loop through all his bits (yes,
 * I agree this is not O(N), but this is the official solution so...) and count
 * how many times the bit one appeared. You can use bitmasks for that. So,
 * create a mask called "ones" and another called "twos". When the jth number
 * appeared one time set the correspond position in the "ones" mask, when it
 * appeared two set the correspond bit in the "twos" mask and unset in the
 * "ones" mask.
 */

#include <stdio.h>

int singleNumber(const int *a, int n1) {
  int ones = 0, twos = 0;
  int i, j, bit;

  for (i = 0; i < n1; i++) {
    for (j = 0; j < 32; j++) {
      // If the jth bit is 0 skip this iteration
      if (!(a[i] & (1 << j))) continue;

      if (ones & (1 << j)) {
        twos = twos | (1 << j);
        ones = ones & ~(1 << j);
      }
      else if (twos & (1 << j)) {
        ones = ones & ~(1 << j);
        twos = twos & ~(1 << j);
      }
      else {
        ones = ones | (1 << j);
      }
    }
  }

  return ones;
}

int main() {
  int p[7] = {3, 5, 1, 5, 5, 3, 3};
  int number = singleNumber(p, 7);

  printf("\n%d\n\n", number);

  int x;
  for (x = 0; x < (1 << 30); ++x) {
    printf("%d\n", x);
  }

  return 0;
}