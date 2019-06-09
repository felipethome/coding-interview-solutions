/**
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 * Example:
 * Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Time complexity: O(N*logN*M), where N is the number of elements in the array
 * and M is the average amount of digits in the numbers.
 *
 * Explanation: first of all we need to manipulate strings because we need to
 * access each digit of these numbers and since our answer will be a string it
 * is easier if we already start our algorithm manipulating strings. We need
 * to implement a custom comparator for the C++ sort() function. Our comparator
 * will receive two elements/strings at each call, let them be called "a" and
 * "b". Then we check if ab > ba, and if it is we return true because we want
 * "a" before "b" (returning true in a comparator means that the first argument
 * "a" must preceed the second argument "b"). When ab is bigger than ba?
 * Starting from the left, when we find ab[i] > ba[i]. Finally, combine this
 * sorted vector in a string and return.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cmp(string a, string b) {
  string ab = a + b;
  string ba = b + a;

  for (int i = 0; i < ab.size(); i++) {
    if (ab[i] == ba[i]) continue;
    return ab[i] > ba[i] ? true : false;
  }

  return false;
}

string largestNumber(const vector<int> &a) {
  vector<string> b;
  string ans = "";

  for (int i = 0; i < a.size(); i++) b.push_back(to_string(a[i]));

  sort(b.begin(), b.end(), cmp);

  for (int i = 0; i < b.size(); i++) ans += b[i];

  int j = 0;
  while (ans[j] == '0' && j + 1 < ans.size()) j++; 

  return ans.substr(j);
}

int main() {
  // vector<int> a = {0, 0, 0, 0, 0};
  // vector<int> a = {00, 0000, 000, 0};
  // vector<int> a = {3, 33, 333, 3333};
  // vector<int> a = {3, 30, 34, 5, 9};
  // vector<int> a = {54, 546, 548, 60};
  vector<int> a = {1, 34, 3, 98, 9, 76, 45, 4};

  string ans = largestNumber(a);

  cout << ans << endl;

  return 0;
}