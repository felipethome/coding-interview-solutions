/**
 * You are given a string, S, and a list of words, L, that are all of the same
 * length. Find all starting indices of substring(s) in S that is a
 * concatenation of each word in L exactly once and without any intervening
 * characters.
 *
 * Example :
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 * Time complexity: O(N * M), where N is the string length and M is the number
 * of words.
 *
 * Explanation: suppose n = S.length(), m = words.size(), l = words[0].length().
 * We need a hashmap to count the frequency of our words, because they can
 * repeat in our words list. So our hashmap has the from <string, int>.
 * We iterate though our words list counting the frequency. Then, we iterate
 * through S from 0 to n - (m * l), because it's not possible to have a
 * substring from all words after n - (m * l). Call the variable controlling
 * this loop "i". Each "i" represents the beginning of a possible substring. So,
 * for each "i" we start another loop where we try to find all occurrences of
 * our words. This internal loop is incremented by the word size in every
 * iteration. We need to use another hashmap in this loop to help us count the
 * occurrences of words, we also need a variable to count how many words we
 * already found because when this variable is equal m we found a substring
 * and we need to add it to our answer. Notice, that when we found more
 * occurrences of a particular word than our original frequency hashmap allows
 * we need to break this internal loop because that "i" will not be a possible
 * beginning of a substring. Also, we need to break when we didn't find the
 * current word in our frequency hashmap.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
  int n = s.length(), m = words.size(), l = words[0].length();
  int ctrl = 0, nextCtrl = 0;
  vector<int> ans;
  unordered_map<string, pair<int, int>> map;
  
  if (n == 0 || m == 0 || l == 0) return ans;
  if (n - (m * l) < 0) return ans;

  for (int i = 0; i < words.size(); i++) {
    unordered_map<string, pair<int, int>>::iterator it = map.find(words[i]);
    if (it != map.end()) (it->second.first)++;
    else map.insert(make_pair(words[i], make_pair(1, 0)));
  }

  for (int i = 0; i <= n - (m * l); i++) {
    int j = i;
    int internalCount = 0;

    while ((j - i) < (m * l)) {
      string curr = s.substr(j, l);
      unordered_map<string, pair<int, int>>::iterator it = map.find(curr);
      j += l;

      if (it != map.end()) {
        pair<int, int> *p = &(it->second);

        if (p->first == p->second - ctrl) {
          break;
        }
        else {
          if (p->second < ctrl) p->second = ctrl + 1;
          else (p->second)++;

          nextCtrl = max(nextCtrl, p->second);
          internalCount++;
          if (internalCount == m && (j - i) == (m * l)) {
            ans.push_back(i);
          }
        }
      }
    }
    
    ctrl = nextCtrl;
  }

  return ans;
}

// vector<int> findSubstring(string s, vector<string>& words) {
//   int n = s.length(), m = words.size(), l = words[0].length();
//   vector<int> ans;
//   unordered_map<string, int> map;
  
//   if (n == 0 || m == 0 || l == 0) return ans;
//   if (n - (m * l) < 0) return ans;

//   for (int i = 0; i < words.size(); i++) {
//     unordered_map<string, int>::iterator it = map.find(words[i]);
//     if (it != map.end()) (it->second)++;
//     else map.insert(make_pair(words[i], 1));
//   }

//   for (int i = 0; i <= n - (m * l); i++) {
//     unordered_map<string, int> currMap;
//     int j = i;
//     int internalCount = 0;

//     while ((j - i) < (m * l)) {
//       string curr = s.substr(j, l);
//       unordered_map<string, int>::iterator it = map.find(curr);
//       j += l;

//       if (it != map.end()) {
//         unordered_map<string, int>::iterator it2 = currMap.find(curr);

//         if (it2 != currMap.end()) {
//           if (it2->second == it->second) break;
//           else (it2->second)++;
//         }
//         else {
//           currMap.insert(make_pair(curr, 1));
//         }

//         internalCount++;
//         if (internalCount == m && (j - i) == (m * l)) ans.push_back(i);
//       }
//     }
//   }

//   return ans;
// }

int main() {
  int n, d;

  // string s = "barfootheblafoofooblafoobarman";
  // string s = "thebarfooblablabarbarbarfooblafoofoo";
  // string s = "thebarfooblablabarfoobarfoo";
  // string s = "thebarfooblablabarfoobarfoobarbarbla";
  // string s = "foobarba";
  // string s = "thefoobarbar";
  // vector<string> w = {"foo", "bar"};

  // string s = "ccacaababcbb";
  string s = "bcabbcaabbccacacbabccacaababcbb";
  vector<string> w = {"c", "b", "a", "c", "a", "a", "a", "b", "c"};

  vector<int> r = findSubstring(s, w);

  cout << "Answer: " << endl;
  cout << "[ ";
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
    if (i != r.size() - 1) cout << "  ";
  }
  cout << "]" << '\n';
  
  return 0;
}