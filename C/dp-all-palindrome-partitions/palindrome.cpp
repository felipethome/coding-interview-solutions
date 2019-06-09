/*
 * Given a string s, partition s such that every string of the partition is a
 * palindrome. Return all possible palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return
 * [
 *   ["a","a","b"]
 *   ["aa","b"],
 * ]
 *
 * Time complexity: probably exponential.
 *
 * Explanation: Walk through the string. At each character position you are,
 * divide the string in a left part and a right part. For example "a" and "ab".
 * Check if the left part is a palindrome and if it is call the function again
 * for the right part. When you arrive at the end of the substring you currently
 * are analysing return a vector<vector<string>> that will be empty if
 * nothing were a palindrome at that particular call. When you return this
 * vector<vector<string>> to a previous call of your function walk through it
 * and for each vector<string> insert at the beginning the left string of that
 * function and then push_back this vector<string> in the
 * vector<vector<string>> of the function.
 *
 * I will try to explain better why this "concatenation" of the vector<string>
 * and vector<vector<string>> works. Suppose, you returned v':
 * v' = [ ["a", "a"], ["aa"] ]
 * And that your prefix (left part) at the current execution of your function is
 * "b". So, you can insert your prefix at the beginning of each vector<string>:
 * v' = [ ["b", a", "a"], ["b", aa"] ]
 * And then push_back each vector<string> of v' in the vector<vector<string>> V
 * of your function:
 * V = [ ["b", a", "a"], ["b", aa"] ]
 * So, trying to summarize, for each prefix (left part) you checked that is a
 * palindrome you will have a vector<vector<string>> v' returned with the
 * possible partitions, so you put your prefix together and push_back in your
 * vector<vector<string>> V.
 *
 * Remember of checking after your loop if the whole substring you are analysing
 * at that call is a palindrome. The whole substring will not be analysed in the
 * loop because it can't be divided in left and right parts.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string strrev(string a) {
  reverse(a.begin(), a.end());
  return a;
}

string copystr(string a) {
  char *c = new char [a.size()+1];
  copy(a.begin(), a.end(), c);
  c[a.size()] = '\0';

  return string(c);
}

bool check(string a) {
  if (a != "" && a == strrev(a)) return true;
  return false;
}

vector<vector<string>> partition(string a) {
  vector<vector<string>> v;

  if (a.size() == 1) {
    vector<string> t;
    t.push_back(a);
    v.push_back(t);
    return v;
  }

  for (int i = 1; i < a.length(); i++) {
    string l = copystr(a).erase(i);
    l.erase(i);
    string r = a.substr(i);

    if (check(l)) {
      vector<vector<string>> v2 = partition(r);

      for (int j = 0; j < v2.size(); j++) {
        vector<string> t;
        t.push_back(l);
        t.insert(t.end(), v2[j].begin(), v2[j].end());
        v.push_back(t);
      }
    }
  }

  if (check(a)) {
    vector<string> t;
    t.push_back(a);
    v.push_back(t);
  }

  return v;
}

int main() {
  // string a = "aab";
  // string a = "aabba";
  string a = "aabbaa";

  // cout << "erase 1: " << copystr(a).erase(1) << '\n';
  // cout << "substr 1: " << a.substr(1) << '\n';
  // cout << "reversed: " << strrev(a) << '\n';
  // cout << "normal: " << a << '\n';
  // cout << "check palindrome (aabaa): " << check("aabaa") << '\n';

  vector<vector<string>> r = partition(a);

  cout << "Answer for " << a << " has " << r.size() << " vectors:" << '\n';
  for (int i = 0; i < r.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << ' ';
    }
    cout << "]" << '\n';
  }

  return 0;
}