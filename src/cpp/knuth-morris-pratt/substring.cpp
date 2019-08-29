/**
 * Check if a substring exists in a string using the Knuth-Morris-Pratt
 * algorithm.
 *
 * Time complexity: O(N + M), where N is the length of the string and M the
 * length of the substring.
 *
 * Explanation: the Knuth-Morris-Pratt algorithm uses the idea that when a
 * mismatch occurs when comparing the pattern and the string the pattern itself
 * encodes enogh information about where in the pattern we should start to try
 * to match characters again. So it generates a table of length M, where M is
 * the length of the pattern with this information.
 *
 * Table: we always start our table with the value zero for the first character
 * and we use two pointer, i and j, to keep track of our prefix and suffixes.
 * Initiate i with 0, and j with 1. When i and j are equal you increment both.
 * When they are not equal, if j - 1 is bigger than 0 you make j = table[j - 1],
 * else you push 0 in the array and increment i.
 *
 * Example:
 * a a b a a b a a a
 * 0 1 0 1 2 3 4 5 2
 *
 * How to use the table: the table information is saying that when a mismatch
 * occurs (s[i] != p[j]) look at the previous index of our table (table[j - 1])
 * to see where we should start the match again in our pattern, withou having to
 * go back in our current string position. For example, lets look at the first
 * three characters of our above pattern with a hypothetical string:
 *
 * p: a a b ...
 *    0 1 0
 * s: a a c ...
 *
 * In "c", a mismatch occurs so we look at the previous index in our table and
 * check where we should start the match again, in this case the table says
 * index 1. So we try to match "c" with "a" and so on. This makes sense, because
 * when we compared "b" with "c" and had a mismatch we had already matched two
 * "a"s, so we are saying: "aac" is not equal "aab", but MAYBE "ac" will be
 * equal to "aa" (that we will see in the next comparison that is actually not
 * equal).
 *
 * Note: when j, the pointer that points to the pattern characters and that we
 * also use to control our table information, is 0 and we have a mismatch
 * (s[i] != p[j]), we just increment i, because of course, our substring doesn't
 * start at s[i].
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildTable(string &sub) {
  int j = 0, i = 1;
  vector<int> table;

  table.push_back(0);

  while (i < sub.length()) {
    if (sub[j] == sub[i]) {
      table.push_back(j + 1);
      i++;
      j++;
    }
    else {
      if (j - 1 < 0) {
        table.push_back(0);
        i++;
      }
      else {
        j = table[j - 1];
      }
    }
  }

  return table;
}

bool findSubstr(string &str, string &sub) {
  if (sub.length() > str.length() || sub.length() == 0) return false;

  int i = 0, j = 0;
  vector<int> table = buildTable(sub);

  while (i < str.length() && j < sub.length()) {
    if (str[i] == sub[j]) {
      i++;
      j++;
    }
    else {
      if (j == 0) {
        i++;
      }
      else {
        j = table[j - 1];
      }
    }
  }

  if (j == sub.length()) return true;
  return false;
}

int main() {
  string str = "abxabcabcaby";
  string sub = "abcaby";

  vector<int> table = buildTable(sub);

  cout << "Table: " << endl;
  cout << "[ ";
  for (int i = 0; i < table.size(); i++) {
    cout << table[i] << " ";
    if (i != table.size() - 1) cout << "  ";
  }
  cout << "]" << endl;

  bool found = findSubstr(str, sub);
  if (found) cout << "Substring found" << endl; 
  else cout << "Substring not found" << endl;

  return 0;
}