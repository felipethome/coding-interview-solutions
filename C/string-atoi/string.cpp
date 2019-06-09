/**
 * Implement atoi to convert a string to an integer.
 * 
 * Example:
 * 
 * Given "9 2704"
 * Return 9
 * 
 * Questions:
 * Q1. Does string contain whitespace characters before the number?
 * A. Yes
 * Q2. Can the string have garbage characters after the number?
 * A. Yes. Ignore it.
 * Q3. If no numeric character is found before encountering garbage characters,
 * what should I do?
 * A. Return 0.
 * Q4. What if the integer overflows?
 * A. Return INT_MAX if the number is positive, INT_MIN otherwise.
 *
 * Time complexity: O(N), where N is the length of the string.
 * Space complexity: O(1).
 *
 * Explanation: there is not much to say here. Iterate through the string
 * convert each number character to a number and add to your answer
 * (ans * 10 + number). Take care of the overflow case in each iteration
 * checking if you are in a case where adding the next number will be larger
 * than INT_MAX (or smaller than INT_MIN).
 */

#include <iostream>

using namespace std;

int atoi(const string &a) {
  int sign = 1, ans = 0, i = 0;

  // Discard initial empty spaces, check if there is a sign to update our sign
  // variable and discard it too.
  while (a[i] == ' ') i++;
  if (a[i] == '-' || a[i] == '+') {
    sign = a[i] == '-' ? -1 : 1; 
    i++;
  }

  // While we have numbers. The '/0' is not in this range so we don't need to
  // check the string size.
  while (a[i] >= '0' && a[i] <= '9') {
    // Check for overflow. The max value for negative integers is one unit
    // larger (in absolute value) than the max value for positive integers.
    if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && a[i] - '0' > 7)) {
      return INT_MAX;
    }
    else if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && a[i] - '0' > 8)) {
      return INT_MIN;
    }
    // Convert the current character to a number based on their ASCII values.
    // The ASCII code for a character that represents a number N minus the
    // character that represents 0 gives N. Multiply by the sign here because
    // this way "ans" will during the whole process be negative if the sign is
    // negative. This is important for the overflow check.
    ans  = 10 * ans + ((a[i] - '0') * sign);
    i++;
  }

  return ans;
}

int main() {
  // string a = "9 2704";
  // string a = "-9 2704";
  // string a = "+12345";
  // string a = "-12345";
  string a = "-12345abcd";

  int r = atoi(a);

  cout << r << endl;

  return 0;
}