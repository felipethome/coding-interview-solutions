/**
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * Example:
 * 
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB 
 * ...
 * 52 -> AZ
 * ...
 * 78 -> BZ
 *
 * Time complexity: O(logN), where N is the given number and log is base 26.
 * Space complexity: O(1).
 *
 * Explanation: this is base 26, but with one difference, that is our number do
 * not start at 0, but at 1. Our 0th symbol is A and our 25th symbol is Z, so
 * we need to subtract 1 from our current input (1 becomes 0, which is A, 26
 * becomes 25 which is Z, 52 becomes AZ, and so on).
 * Notice that using the ASCII values to get the letters is better than using
 * a dicitionary.
 */

#include <iostream>
#include <vector>

using namespace std;

string convertToTitle(int n) {
  string ans = "";

  while (n > 0) {
    ans.pus_back((char)((n - 1) % 26 + 'A'));
    n = (n - 1) / 26;
  }
  
  reverse(ans.begin(), ans.end());

  return ans;
}

int main() {
  // int a = 4;
  // int a = 28;
  // int a = 26;
  // int a = 52;
  // int a = 2600;
  int a = 943566;

  string r = convertToTitle(a);

  cout << r << endl;

  return 0;
}