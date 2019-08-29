/**
 * Write a function to find the longest common prefix string amongst an array
 * of strings. Longest common prefix for a pair of strings S1 and S2 is the
 * longest string S which is the prefix of both S1 and S2.
 * As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
 * 
 * Given the array of strings, you need to find the longest S which is the
 * prefix of ALL the strings in the array.
 * 
 * Example:
 * Given the array,
 * [
 *   "abcdefgh",
 *   "aefghijk",
 *   "abcefgh"
 * ]
 *
 * The answer would be “a”.
 *
 * Time complexity: O(N^2), where N is the length of the largest string.
 * Space complexity: O(N).
 *
 * Explanation: iterate from 0 to the length of the string with the smallest
 * length. For each character a[i][0] check if every other character a[i][j]
 * is equal. If all of them are equal add this character to you answer,
 * otherwise return the answer.
 */

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &a) {
  int minLen = INT_MAX;
  string result = "";

  for (int i = 0; i < a.size(); i++) minLen = min(minLen, (int)a[i].size());

  for (int i = 0; i < minLen; i++) {
    int count = 0;

    for (int j = 0; j < a.size(); j++) {
      if (a[j][i] == a[0][i]) count++;
      else break;
    }
    
    if (count == a.size()) result.push_back(a[0][i]);
    else break;
  }

  return result;
}

int main() {
  vector<string> a = {
    "abcdefgh",
    "aefghijk",
    "abcefgh"
  };

  string r = longestCommonPrefix(a);

  cout << r << endl;

  return 0;
}