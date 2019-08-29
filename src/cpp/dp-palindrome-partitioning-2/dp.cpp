/**
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return the minimum cuts needed for a palindrome partitioning
 * of s.
 * 
 * Example: 
 * Given,
 * s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced
 * using 1 cut.
 *
 * Time complexity: O(N^2), where N is the length of the string.
 * Space complexity: O(N).
 *
 * Explanation: iterate over the string. For each character "i" check all
 * the substrings made by the union of "i" with "j = i .. 0" are palindrome
 * and when they are get min(current, dp[j - 1]). For example:
 * s = abba
 * i = 0, j = 0: dp = [0]
 * i = 1, j = 1 .. 0:
 *   substr(1 to 1) = b, so it is palindrome and gives us minCuts = 1
 *   substr(0 to 1) = ab, it is not a palindrome
 *   dp = [0 1]
 * i = 2, j = 2 .. 0:
 *   substr(2 to 2) = b, so it is palindrome and give us minCuts = 2
 *   substr(2 to 1) = bb, so it is palindrome and give us minCuts = 1
 *   substr(2 to 0) = abb, it is not a palindrome
 *   dp = [0 1 1]
 * i = 3, j = 3 .. 0:
 *   substr(3 to 3) = a, so it is palindrome and give us minCuts = 2
 *   substr(3 to 2) = ab, it is not a palindrome
 *   substr(3 to 1) = abb, it is not a palindrome
 *   substr(3 to 0) = abba, it is a palindrome and give us minCuts = 0
 *   dp = [0 1 1 0]
 *
 * Now that we know our algorithm there is room for more improvements.
 * Especificaly we need to make the algorithm that check if a string is
 * palindrome faster. And we can use more DP for that. We need a square matrix
 * N x N, where N is the length of the string where we gonna fill just half of
 * if (we gonna fill the diagonal and all the elements under it). This is
 * because this half matrix is enough to give us all the possible palindromes
 * of a string. For example:
 * 0 1 2 3
 * a b b a
 * Give us: 0, 1, 2, 3, 0->1, 0->2, 0->3, 1->2, 1->3, 2->3. Notive how j is
 * never bigger than i, otherwise we would have substrings like 3->2, which is
 * the same as 2->3.
 * Our diagonal elements in the matrix are i = j, and of course they are true
 * because every single letter (substr(i, i) = one letter) in the string is a
 * palindrome. Now we check if a[i] == a[j] AND isPalindrome[i - 1][j + 1] is
 * true. This "if" statement is basically saying that if the letter at the
 * beginning and end of the substring are equal and the substring from j + 1
 * to i - 1 is a palindrome (this j + 1 to i - 1 substring is the middle, or in
 * other words, everything between the beginning and end of the current
 * substring) so this current substring is also a palindrome. Notice I'm not
 * wrong saying j + 1 to i - 1 substring, because this is what the element at
 * isPalindrome[i - 1][j + 1] needs to represent.
 */

#include <iostream>
#include <vector>

using namespace std;

int minCut(string s) {
  int n = s.size();
  if (!n) return 0;

  vector<vector<bool> > isPalindrome(n, vector<bool>(n, false));
  int dp[n];

  for (int i = 0; i < n; ++i){
    isPalindrome[i][i] = true;
    dp[i] = i;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      if (s[i] == s[j] && (i - j < 2 || isPalindrome[i - 1][j + 1])) {
        if (j == 0) {
          dp[i] = 0;
        }
        else {
          isPalindrome[i][j] = true;
          dp[i] = min(dp[j - 1] + 1, dp[i]);
        }
      }
    }
  }

  return dp[n - 1];
}

// bool isPalindrome(string &str, int s, int e) {
//   if (str.size() == 0) return true;

//   for (int i = s, j = 0; i < e; i++, j++) {
//     if (str[i] != str[e - j - 1]) return false;
//   }

//   return true;
// }

// int minCut(string str) {
//   if (str.size() <= 1) return 0;

//   vector<int> dp;

//   for (int i = 0; i < str.size(); i++) {
//     int j = i, mc = INT_MAX;

//     while (j >= 0) {
//       if (isPalindrome(str, j, i + 1)) {
//         if (j == 0) mc = -1;
//         else mc = min(mc, dp[j - 1]);
//       }
//       j--;
//     }
//     dp.push_back(mc + 1);
//   }

//   return dp.back();
// }

// bool isPalindrome(string &str, int s, int l) {
//   if (str.size() == 0) return true;

//   for (int i = s, j = 0; i < (s + l); i++, j++) {
//     if (str[i] != str[(s + l) - j - 1]) return false;
//   }

//   return true;
// }

// void partition(string &str, int cuts, int *ans, int s) {
//   if (s == str.size()) *ans = min(*ans, cuts);

//   for (int i = s; i < str.size(); i++) {
//     if (isPalindrome(str, s, i - s + 1)) {
//       partition(str, cuts + 1, ans, i + 1);
//     }
//   }
// }

// int minCut(string str) {
//   if (str.size() <= 1) return 0;

//   int ans = INT_MAX;

//   partition(str, 0, &ans, 0);

//   return ans - 1;
// }

int main() {
  // string s = "";
  // string s = "a";
  // string s = "aa";
  // string s = "ab";
  // string s = "abc";
  string s = "aabcc";

  int m = minCut(s);
  cout << "min: " << m << endl;

  return 0;
}