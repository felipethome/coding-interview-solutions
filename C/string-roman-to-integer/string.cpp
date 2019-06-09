/**
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Read more details about roman numerals at Roman Numeric System
 * 
 * Example:
 * 
 * Given "XIV"
 * Return 14
 * Given "XX"
 * Output 20
 *
 * Time complexity: O(N), where N is the length of the given string.
 * Space complexity: O(1).
 *
 * Explanation: you need a dictionary to return map the letters to their
 * respective number. There are two cases:
 * 1. There is a letter that has a smaller value than the following letter. In
 * this case you need to add to the result the difference between the larger
 * and the smaller value. For example, "IV", we add to the result 5 - 1 = 4.
 * 2. The above condition is not true, so we just add to the result the value
 * of the current letter.
 */

#include <iostream>

using namespace std;

int getNumber(char c) {
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}

int romanToInteger(string a) {
  int result = 0;
  char prev = '0';

  for (int i = a.size(); i >= 0; i--) {
    if (getNumber(a[i]) < getNumber(prev)) result = result - getNumber(a[i]);
    else result = result + getNumber(a[i]);
    prev = a[i];
  }

  return result;
}

int main() {
  string a = "VIII";

  int r = romanToInteger(a);

  cout << r << endl;

  return 0;
}