/**
 * Given two words A and B, find the minimum number of steps required to convert
 * A to B. Each operation is counted as 1 step.
 * You have the following 3 operations permitted on a word:
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * Example: 
 * edit distance between "Anshuman" and "Antihuman" is 2.
 * Operation 1: Replace s with t.
 * Operation 2: Insert i.
 *
 * Time complexity: O(M * N), where M is the length of string 1 and N is the
 * length of string 2.
 * Space complexity: O(M * N).
 *
 * Explanation: our dp variable will have size M * N, where M is the length of
 * string 1 and N is the length of string 2. The idea is that for each pair of
 * characters that we are looking at we decide which operation we want to
 * perform (insertion, deletion, replace). For example, imagine we have:
 *     0 1 2 3
 * s1: a a b
 * s2: b b b a
 * And we are looking to the pair (s1[2] = b, s2[3] = a).
 * We can insert "a" (s2[3]) and reuse the result we have for *(aab, bbb), or
 * we can delete "b" (s1[2]) and reuse the result we have for **(aa, bbba), or
 * we can replace "b" with "a" (s1[2] with s2[3]) and reuse the result we have
 * for ***(aa, bbb).
 * *: dp[i - 1][j]
 * **: dp[i][j - 1]
 * ***: dp[i - 1][j - 1]
 * The results above suppose the columns of the dp matrix are composed by s1,
 * and the rows by s2.
 * Notice you need to add 1 for the results above because you need to take into
 * account you are performing an operation.
 * Notice too that if characters of the pair we are looking at are equal the
 * result is a little different, because in the case of the replace operation
 * you don't need to add 1.
 *
 * The complete dp matrix for the example above would be:
 *      a a b
 *    0 1 2 3
 * b: 1 1 2 2
 * b: 2 2 2 2
 * b: 3 3 3 2
 * a: 4 3 3 3
 *
 * The first column and first row are for empty strings, where the number of
 * operations is decided by the size of the non-empty string.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int minDistance(string a, string b) {
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

  for (int i = 0; i <= a.size(); i++) dp[i][0] = i;
  for (int i = 0; i <= b.size(); i++) dp[0][i] = i;

  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
      }
      else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      }
    }
  }

  return dp[a.size()][b.size()];
}

int main() {
  // string a = "ansae";
  // string b = "anisadce";
  
  // string a = "anisadce";
  // string b = "ansae";
  
  // string a = "ansae";
  // string b = "ansae";
  
  // string a = "";
  // string b = "ansae";
  
  // string a = "e";
  // string b = "anisadce";
  
  // string a = "bbbaaba";
  // string b = "aababbb";
  
  // string a = "bbbaabaa";
  // string b = "aababbabb";
  
  string a = "abbbaaaaaaabaabaaaa";
  string b = "abaabbbaabaaabaabab";

  int m = minDistance(a, b);

  cout << "m: " << m << endl;

  return 0;
}