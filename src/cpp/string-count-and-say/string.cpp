/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as one 1 or 11.
 * 11 is read off as two 1s or 21.
 * 21 is read off as one 2, then one 1 or 1211.
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 * Example:
 * 
 * if n = 2,
 * the sequence is 11.
 *
 * Time complexity: hard to tell, but will be something like O(N * M), where
 * N is the given input and M is the length of the largest string.
 *
 * Explanation: I did a straight forward solution. Just count how many times
 * each digit occurred and build a new string for each i until i is N.
 */

#include <iostream>

using namespace std;

string countAndSay(int n) {
  if (n == 0) return "";
  
  string ans = "1";
  
  for (int i = 1; i < n; i++) {
    string t = "";
    for (int j = 0; j < ans.size();) {
      int k = j, r = 0;
      char first = ans[k];

      while (ans[k] == first) {
        k++;
        r++;
      }

      j = k;
      t += to_string(r) + first;
    }
    swap(ans, t);
  }
  
  return ans;
}

int main() {
  int a = 5;

  string r = countAndSay(a);

  cout << r << endl;

  return 0;
}