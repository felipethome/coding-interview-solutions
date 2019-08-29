/**
 * Given an integer, convert it to a roman numeral, and return a string
 * corresponding to its roman numeral version.
 * Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Example:
 * Given 5, return "V".
 * Given 14, return "XIV".
 *
 * Time complexity: O(1), it is proportional to the number of 10th powers, but
 * since we have at most 10^3 numbers it is constant.
 *
 * Explanation: of course we need a dicitionary to get our symbols. We need to
 * get with this dicitionary the roman strings of each of our 10th powers.
 */

#include <iostream>

using namespace std;

string intToRoman(int a) {
  // 1000, 2000, 3000
  string M[] = {"", "M", "MM", "MMM"};
  // 100, 200, 300, .. 900
  string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  // 10, 20, ... 90
  string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  // 1, 2, ... 9
  string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

  return M[a / 1000] + C[(a % 1000) / 100] + X[(a % 100) / 10] + I[a % 10];
}

int main() {
  // int a = 7;
  // int a = 10;
  // int a = 3999;
  // int a = 2756;
  // int a = 1234;
  // int a = 648;
  int a = 86;

  string r = intToRoman(a);

  cout << r << endl;

  return 0;
}