/**
 * Reverse digits of an integer.
 * 
 * Example:
 * x = -123,
 * return -321
 * 
 * Return 0 if the result overflows and does not fit in a 32 bit signed integer.
 *
 * Time complexity: O(N), where N is the number of digits in the number.
 *
 * Explanation: check the sign and store it is a variable (1 positive, -1
 * negative). Reverse the number digit by digit using mod and division. At
 * each iteration you multiply your current number by 10 and add the mod by
 * 10 of your number, then divide the number by 10 and keep doing it until your
 * number is 0. The overflow checking is easy. If INT_MAX / 10 is bigger than
 * your current number you know the number will overflow in the next iteration.
 * Or if current_value * 10 is bigger than INT_MAX - a % 10 you also know the
 * next iteration will overflow.
 */

#include <iostream>

int reverse(int a) {
  if (a == 0) return 0;
  
  int sign = a < 0 ? -1 : 1; 
  int b = abs(a), ans = 0;
  
  while (b != 0) {
    if (ans > INT_MAX / 10 || ans * 10 > INT_MAX - (b % 10)) return 0;

    ans = (ans * 10) + (b % 10);
    b /= 10;
  }
  
  return ans * sign;
}

using namespace std;

int main() {
  int a = -123;

  cout << reverse(a) << endl;

  return 0;
}