/**
 * Given a column title as appears in an Excel sheet, return its corresponding
 * column number.
 * 
 * Example:
 * 
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 *
 * Time complexity: O(logN), where N is the given number and log is base 26.
 * Space complexity: O(1).
 *
 * Explanation: base 26, transform each letter to its respective number and
 * multiply by the correct base, then add the current result to the answer.
 * Since it is base 26, bases will be = 26^0, 26^1, 26^2, and so on.
 */

#include <iostream>
#include <vector>

using namespace std;

int convertToNumber(string a) {
  int ans = 0, base = 1;

  for (int i = a.size() - 1; i >= 0; i--) {
    ans += (a[i] - 'A' + 1) * base;
    base *= 26;
  }

  return ans;
}

int main() {
  // string a = "D";
  // string a = "Z";
  // string a = "AB";
  // string a = "AZ";
  string a = "BAQTZ";

  int r = convertToNumber(a);

  cout << r << endl;

  return 0;
}