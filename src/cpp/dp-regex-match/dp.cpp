/**
 * Implement wildcard pattern matching with support for '?' and '*'.
 * '?' : Matches any single character.
 * '*' : Matches any sequence of characters (including the empty sequence).
 * Note: The pattern must match the entire string.
 * 
 * Examples :
 * isMatch("aa","a") → 0
 * isMatch("aa","aa") → 1
 * isMatch("aaa","aa") → 0
 * isMatch("aa", "*") → 1
 * isMatch("aa", "a*") → 1
 * isMatch("ab", "?*") → 1
 * isMatch("aab", "c*a*b") → 0
 *
 * Return 1/0 for this problem.
 *
 * Time complexity: O(N*M), where N is the length of the string, and M is the
 * length of the pattern.
 * Space complexity: O(M), where M is the length of the pattern.
 *
 * Explanation: I used a different approach. The '*' in the pattern are not
 * important to tell if there will be a match or not because they can match
 * the empty string or anything else. What really tells you if a pattern will
 * occur are the characters and '?' in the pattern. So, I divided the pattern
 * in pieces at each '*', and each piece is made only of characters and '?'.
 * Then, I try to check if all of these pieces exist in the input string. A
 * problem with this approach is that it could be tricky to check the beginning
 * and end of our input string, because I'm looking for substrings in the input,
 * which can return false positives when we find a substring that we wanted
 * to start at the very beginning of the input, example:
 * input: ba
 * pattern: a
 * This would return true, because "a" is a substring of "ba", but it should
 * return false because the "a" we matched should be at the beginning. To fix
 * these cases I insert in the pattern and input string the characters ^ and $
 * like this:
 * input: ^ba$
 * pattern: ^a$
 * That fix the problem because "a" is still a substring of "ba", but now we
 * need to find "^a$" which will never happen unless "a" was the first and last
 * character of the input string.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int checkStrings(string str, string substr, int start) {
  if (substr.size() == 0) return start;

  for (int i = start; i < str.size(); i++) {
    int count = 0, k = i;
    for (int j = 0; j < substr.size(); j++) {
      if (substr[j] == '?' || str[k] == substr[j]) {
        count++;
        if (count == substr.size()) return k;
        else k++;
      }
      else {
        break;
      }
    }
  }

  return -1;
}

int isMatch(const string &s, const string &p) {
  string str = "^" + s + "$";
  string ptr = "^" + p + "$";
  vector<string> pieces;
  int i = 0, j = 0;

  while (j <= ptr.size()) {
    if (j < ptr.size() && ptr[j] != '*') j++;
    else {
      if (j - i > 0) pieces.push_back(ptr.substr(i, j - i));
      j++;
      i = j;
    }
  }

  i = 0;
  j = 0;

  while (i < str.size() || j < pieces.size()) {
    int lastIndex = checkStrings(str, pieces[j], i);

    if (lastIndex > -1) i = lastIndex + 1;
    else return 0;

    j++;
  }

  return 1;
}

// int _isMatch(const string &s, const string &p, int i, int j, vector<vector<int>> &cache) {
//   if (i < s.size() && j < p.size() && cache[i][j] != -1) {
//     return cache[i][j];
//   }

//   if (i == s.size() && j == p.size()) {
//     return 1;
//   }

//   int ans = 0;

//   if (j < p.size() && p[j] == '*') {
//     int b1 = 0, b2 = 0;
//     if (i < s.size()) b1 = _isMatch(s, p, i + 1, j, cache);
//     if (j < p.size()) b2 = _isMatch(s, p, i, j + 1, cache);
//     ans = b1 || b2;
//   }
//   else if (i < s.size() && (p[j] == '?' || s[i] == p[j])) {
//     int b = _isMatch(s, p, i + 1, j + 1, cache);
//     ans = b;
//   }
  
//   if (i < s.size() && j < p.size()) cache[i][j] = ans;

//   return ans;
// }

// int isMatch(const string &s, const string &p) {
//   vector<vector<int>> cache;

//   for (int i = 0; i < s.size(); i++) {
//     vector<int> temp;
//     for (int j = 0; j < p.size(); j++) {
//       temp.push_back(-1);
//     }
//     cache.push_back(temp);
//   }

//   return _isMatch(s, p, 0, 0, cache);
// }

// int isMatch(const string &s, const string &p) {
//   stack<pair<int, int>> stk;
//   int i = 0, j = 0;

//   while (i < s.size() || j < p.size()) {
//     if (p[j] != '*') {
//       if (i < s.size() && (p[j] == '?' || s[i] == p[j])) {
//         i++;
//         j++;
//       }
//       else if (stk.size() != 0) {
//         pair<int, int> indices = stk.top();
//         stk.pop();
//         i = indices.first;
//         j = indices.second;
//       }
//       else {
//         return 0;
//       }
//     }
//     else {
//       j++;
//       while (i < s.size()) {
//         stk.push(make_pair(i, j));
//         i++;
//       }
//     }
//   }

//   return 1;
// }

int main() {
  vector<pair<string, string>> tests;

  // True
  tests.push_back(make_pair("", ""));
  tests.push_back(make_pair("", "*"));
  tests.push_back(make_pair("a", "a"));
  tests.push_back(make_pair("aaa", "********"));
  tests.push_back(make_pair("abc", "a*?"));
  tests.push_back(make_pair("abcdba", "a*?b?"));
  tests.push_back(make_pair("abcdbabc", "a*?d?*c"));
  tests.push_back(make_pair("abcdbabc", "a*?d?*c*"));
  tests.push_back(make_pair("abcdbabcffab", "a*?d?*c*ab"));
  
  // False
  tests.push_back(make_pair("", "a"));
  tests.push_back(make_pair("abcdbabc", "a*?d?*c?"));
  tests.push_back(make_pair("abcdbabc", "a*?a?*c?"));

  for (int i = 0; i < tests.size(); i++) {
    pair<string, string> inputs = tests[i];
    string s = inputs.first;
    string p = inputs.second;

    int isPossible = isMatch(s, p);

    if (isPossible) cout << "Is possible." << endl;
    else cout << "Is not possible." << endl;
  }

  return 0;
}