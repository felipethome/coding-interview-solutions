/**
 * Given a string s and a dictionary of words dict, add spaces in s to construct
 * a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 * 
 * Examples:
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * A solution is ["cats and dog", "cat sand dog"] 
 *
 * Time complexity: O(N^3), where N is the length of the string.
 * Space complexity: probably O(N^3)
 *
 * Explanation: first of all this is dynamic programming so we gonna have a
 * variable vector<vector<string>>dp. Traverse the string from the end to the
 * beginning with a variable i. At each position i, try all the possible words
 * from i till the end of the string. When you find a match for one of these
 * words in your dictionary combine this matched word with all the strings you
 * were able to assemble at the position where this matched word ends + 1 using
 * your dp variable. Store the result of these combinations in your dp variable
 * at position i.
 *
 * For example, suppose you have:
 * a: "dogcatsand"
 * dict: "dog", "cat", "cats", "and", "sand"
 *
 * And at some point of our running we have:
 * Matched word "dog", starts at position i = 0 and ends at position 2.
 * In our dp we have at position 3 ["cat sand", "cats and"].
 * So we combine "dog" with our dp at position 3 getting
 * ["dog cat sand", "dog cats and"]
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> wordBreak(string a, vector<string> &b) {
  unordered_set<string> dict(b.begin(), b.end());
  vector<vector<string>> dp(a.length() + 1, vector<string>(0));

  // initialize the valid values
  dp[a.length()].push_back("");

  // generate solutions from the end
  for(int i = a.length() - 1; i >= 0; i--) {
    vector<string> t;

    // Try all possible words from i till the end of the string
    for(int j = i + 1; j <= a.length(); j++) {
      string word = a.substr(i, j - i);

      if (dict.find(word) != dict.end()) {
        // If we find a word at position j - 1 we need to combine it with all
        // the strings that we were able to assemble at position j
        for (int k = 0; k < dp[j].size(); k++) {
          t.push_back(word + (dp[j][k].empty() ? "" : " ") + dp[j][k]);
        }
      }
    }

    dp[i] = t;
  }
  
  return dp[0];
}

// bool findWord(vector<string> &b, string a, int s, int e) {
//   for (int i = 0; i < b.size(); i++) {
//     int j = 0, k = s;

//     while (j < b[i].size() && k < e) {
//       if (b[i][j] != a[k]) break;
//       j++;
//       k++;
//     }

//     if (j == b[i].size() && k == e) return true;
//   }

//   return false;
// }

// vector<string> wordBreak(string a, vector<string> &b) {
//   if (a.size() == 0 || b.size() == 0) return vector<string>();

//   vector<string> ans;
//   vector<vector<int>> dp;
//   dp.push_back(vector<int>(1, a.size()));

//   for (int i = a.size() - 1; i >= 0; i--) {
//     vector<vector<int>> nextDp;

//     for (int j = 0; j < dp.size(); j++) {
//       vector<int> t;

//       if (dp[j].back() == 0) nextDp.push_back(dp[j]);

//       for (int k = dp[j].back() - 1; k >= 0; k--) {
//         if (findWord(b, a, k, dp[j].back())) t.push_back(k);
//       }

//       for (int k = 0; k < t.size(); k++) {
//         vector<int> t2 = dp[j];
//         t2.push_back(t[k]);
//         nextDp.push_back(t2);
//       }
//     }

//     if (nextDp.size()) dp.swap(nextDp);
//   }

//   for (int i = 0; i < dp.size(); i++) {
//     string t = "";
//     if (dp[i].back() == 0) {
//       for (int j = 1; j < dp[i].size(); j++) {
//         if (j > 1) t = a.substr(dp[i][j], dp[i][j - 1] - dp[i][j]) + " " + t;
//         else t = a.substr(dp[i][j], dp[i][j - 1] - dp[i][j]);
//       }
//       ans.push_back(t);
//     }
//   }

//   sort(ans.begin(), ans.end());

//   return ans;
// }

int main() {
  // string a = "ccc";
  // vector<string> d = {"c", "cc"};

  // string a = "b";
  // vector<string> d = {"aabbb"};

  string a = "catsanddog";
  vector<string> d = {"cat", "cats", "and", "sand", "dog"};

  vector<string> r = wordBreak(a, d);

  cout << "Number of strings: " << r.size() << endl;

  for (int i = 0; i < r.size(); i++) {
    cout << "`" << r[i] << "`" << endl;
  }

  return 0;
}