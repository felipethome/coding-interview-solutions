/**
 * Given a positive integer which fits in a 32 bit signed integer, find if it
 * can be expressed as A^P where P > 1 and A > 0. A and P both should be
 * integers.
 * 
 * Example:
 * 
 * Given 4
 * Output True, because 2^2 = 4. 
 *
 * Time complexity: O(NlogN), where N is the given number. I believe it is
 * NlogN because we iterate over all possible bases from 2..N - 1 and for all
 * these bases we multiply them until we possibly get the result. The number of
 * times we will perform multiplications for a possible base will be log for
 * that base of N.
 * Space complexity: O(1).
 *
 * Explanation: Iterate through the all numbers from 2..N - 1. For each of these
 * numbers multiply it by itself until you get N or a number larger than N.
 */

#include <iostream>

using namespace std;

bool isPower(int n) {
  if (n == 0) return false;
  if (n == 1) return true;
  
  for (int base = 2; base < n; base++) {
    int curr = 1;

    while (curr < n) {
      curr *= base;
      if (curr == n) return true;
    }
  }

  return false;
}

int main() {
  int a = 4;

  if (isPower(4)) cout << "Can be written as power." << endl;
  else cout << "Can not be written as power." << endl;

  return 0;
}