/**
 * Given a string s and a dictionary of words dict, determine if s can be
 * segmented into a space-separated sequence of one or more dictionary words.
 * Return 0 / 1 ( 0 for false, 1 for true ) for this problem

 * Example:
 * s = "myinterviewtrainer",
 * dict = ["trainer", "my", "interview"].
 * Return 1 ( corresponding to true ) because "myinterviewtrainer" can be 
 * segmented as "my interview trainer".
 *
 * Time complexity: O(N^3), where N is the length of the string.
 * Space complexity: probably O(N^3)
 *
 * Explanation: this problem is simpler than word-break-II, we just need a
 * vector<bool> dp because we are not interested in all the solutions, but if
 * it is possible to have a valid sentence. Traverse the string from the end to
 * the beginning with a variable i. At each position i, try all the possible
 * words from i till the end of the string. When you find a match for one of
 * these words in your dictionary make dp[i] = dp[j] (j is the index where the
 * word ends + 1). Then if dp[i] became true stop your inner loop (the one
 * looking for possible words that start at i) because what matters it that at
 * i we have a valid sentence. Return dp[0].
 *
 * Check the solution for word-break-II if you want more details.
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int wordBreak(string a, vector<string> &b) {
  unordered_set<string> dict(b.begin(), b.end());
  vector<bool> dp(a.length() + 1, false);

  // initialize the valid values
  dp[a.length()] = 1;

  // generate solutions from the end
  for(int i = a.length() - 1; i >= 0; i--) {
    // Try all possible words from i till the end of the string, and as soon
    // as we find a valid combination break the loop.
    for(int j = i + 1; j <= a.length() && dp[i] == false; j++) {
      string word = a.substr(i, j - i);
      if (dict.find(word) != dict.end()) dp[i] = dp[j];
    }
  }
  
  return dp[0];
}

int main() {
  // string a = "ccc";
  // vector<string> d = {"c", "cc"};

  // string a = "b";
  // vector<string> d = {"aabbb"};

  string a = "catsanddog";
  vector<string> d = {"cat", "cats", "and", "sand", "dog"};

  bool possible = wordBreak(a, d);

  if (possible) cout << "Is possible" << endl;
  else cout << "Is not possible" << endl;

  return 0;
}