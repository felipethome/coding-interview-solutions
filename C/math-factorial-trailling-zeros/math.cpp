/**
 * Given an integer N, return the number of trailing zeros in n!.
 * 
 * Notes:
 * 1. Your solution should be in logarithmic time complexity.
 * 
 * Example:
 * N = 5
 * N! = 120 
 * Number of trailing zeros = 1, so, return 1
 *
 * Time complexity: O(logN), where is the given number and log is base 5.
 * Space complexity: O(1).
 *
 * Explanation: factorial of N is the multiplication of all numbers from 1 to
 * N. So, to add a zero to the answer we need to multiply by 10 and number
 * 10's come from the multiplication of an even number multiplied by 5. We
 * don't need to worry about even numbers because there will always be plenty
 * of them to multiply our numbers 5, so what we need to do is to count the
 * number of 5's is the multiplication. For example, for N = 100 we have:
 *
 * 100 / 5 = 20, so there are 20 multiples of 5 from 1 to 100.
 * And for this 20 multiples there are 20 / 5 = 4 another multiples of 5.
 * So, we get 24 zeros.
 *
 * If we expand the multiplication we can see easily see the above fact:
 * 1 * 2 * ... * 10 * 11 * ... 25 ... 100
 * 1 * 2 * ... * (2 * 5) * 11 * ... (5 * 5) ... 100
 */

#include <iostream>

using namespace std;

int trailingZeroes(int a) {
  int ans = 0;
  
  while (a >= 5) {
    a /= 5;
    ans += a;
  }
  
  return ans;
}


int main() {
  int a = 100;

  int r = trailingZeroes(a);

  cout << r << endl;

  return 0;
}