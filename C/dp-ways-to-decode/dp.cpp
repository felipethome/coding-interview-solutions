/**
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 *
 * Example:
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.
 *
 * Time complexity: O(N), where N is the length of the message.
 * Space complexity: O(1).
 *
 * Explanation: this problem is kinda like Fibonacci. For each character of
 * your encoded string you have two options: or you use this character alone
 * and check it against your map (that would give you numbers from 1-9), or
 * you get this character plus its neighbor (that would give you numbers from
 * 10-26). So, we start from the end of our array and for each character/number
 * of our encoded string we get the number of ways the substring after this
 * character can be decoded plus the number of ways the substring after this
 * character and its neighbor can be decoded. The answer would be a Fibonacci
 * number of it wasn't the fact that at each time we are checking our character
 * and its number we need to be sure the number is between 1 and 26, otherwise
 * if it is zero we have zero ways to decode that substring and if it is larger
 * than 26 we don't add the number of ways the substring after the current
 * character and its neightbor can be decoded, but instead just the number of
 * ways the substring after this current character can be decoded.
 */

#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string a) {
  if (a.size() == 0 || (a.size() == 1 && a[0] == '0')) return 0;
  if (a.size() == 1) return 1;

  vector<int> ans(a.length() + 1, 0);

  ans[0] = 1;

  for (int i = a.size() - 1, j = 1; i >= 0; i--, j++) {
    if (stoi(a.substr(i, 1)) >= 1) {
      if (i + 1 < a.size() && stoi(a.substr(i, 2)) <= 26) {
        ans[j] = ans[j - 1] + ans[j - 2];
      }
      else {
        ans[j] = ans[j - 1];
      }
    }
  }

  return ans[ans.size() - 1];
}

/**
 * This version uses constant space.
 */
int numDecodings2(string a) {
  if (a.size() == 0 || (a.size() == 1 && a[0] == '0')) return 0;
  if (a.size() == 1) return 1;

  int secondToLast = 1, thirdToLast, ans = 0;

  for (int i = a.size() - 1; i >= 0; i--) {
    if (stoi(a.substr(i, 1)) >= 1) {
      if (i + 1 < a.size() && stoi(a.substr(i, 2)) <= 26) {
        ans = secondToLast + thirdToLast;
      }
      else {
        ans = secondToLast;
      }
    }
    else {
      ans = 0;
    }

    thirdToLast = secondToLast;
    secondToLast = ans;
  }

  return ans;
}

int main() {
  string a = "10"; // 1
  // string a = "12"; // 2
  // string a = "123"; // 3
  // string a = "123123"; // 9
  // string a = "1231012031230"; // 0
  // string a = "123101203123"; // 9
  // string a = "101203123"; // 3
  // string a = "10120312"; // 2

  int num = numDecodings(a);

  cout << "num: " << num << endl << endl;

  num = numDecodings2(a);

  cout << "num2: " << num << endl;

  return 0;
}