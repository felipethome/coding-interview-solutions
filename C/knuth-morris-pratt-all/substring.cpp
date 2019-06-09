/**
 * Find all substrings occurrences in a string using the Knuth-Morris-Pratt
 * algorithm.
 *
 * Time complexity: O(N + M), where N is the length of the string and M the
 * length of the substring.
 *
 * Explanation: the Knuth-Morris-Pratt is the same. What changes is that this
 * time we gonna use the table.back() element (that is useless when we are
 * looking for the first occurrence of the pattern in our string) to reinitiate
 * the matching process. So, each time we find the pattern we push the index
 * where the pattern started in our string in our answer and we reinitiate j,
 * the pointer that points to our pattern characters and that we also use to
 * control our table information, to table.back(). It makes sense, because
 * this means: when you find a substring use the information of the last
 * character of the pattern to tell us how much we can reuse of our just matched
 * pattern to find another pattern.
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

vector<int> findAllSubstr(string &str, string &sub) {
  vector<int> ans;

  if (sub.length() > str.length() || sub.length() == 0) return ans;

  int i = 0, j = 0;
  vector<int> table = buildTable(sub);

  while (i < str.length() && j < sub.length()) {
    if (str[i] == sub[j]) {
      i++;
      j++;

      if (j == sub.length()) {
        ans.push_back(i - sub.length());
        j = table.back();
      }
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

  return ans;
}

int main() {
  string str = "abacacaggaabacdacabaca";
  string sub = "aca";

  vector<int> table = buildTable(sub);

  cout << "Table: " << endl;
  cout << "[ ";
  for (int i = 0; i < table.size(); i++) {
    cout << table[i] << " ";
    if (i != table.size() - 1) cout << "  ";
  }
  cout << "]" << endl;

  vector<int> r = findAllSubstr(str, sub);

  cout << "Answer: " << endl;
  cout << "[ ";
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
    if (i != r.size() - 1) cout << "  ";
  }
  cout << "]" << endl;

  return 0;
}