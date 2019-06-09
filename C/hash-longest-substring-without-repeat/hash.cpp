/**
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Example:
 * The longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3.
 * 
 * For "bbbbb" the longest substring is "b", with the length of 1.
 *
 * Time complexity: O(N), where N is the length of the given string.
 *
 * Explanation: iterate over the string and keep two variables: a variable for
 * the start of your substring (call it s), and another one for the end
 * (call it e). Also, keep a map<char, int>. The key of the map store a
 * character and the value store the index where that value was first found.
 * 
 * When you, during your iteration, find a character that is already in the map
 * you need to:
 * 1. Check if the substring you just found is larger than the one you had
 * before.
 * 2. Update your start variable s to the next index from where you found the
 * character for the first time (in other words, to the int value from your map
 * plus 1).
 * 3. Make e = s.
 * 4. Clear your map.
 *
 * When you don't find the current character in your map you add the character
 * to your map with the character as the key and its index as value, and
 * increment e.
 * 
 * Stop the iteration when  s or e are equal or larger to the
 * original string length.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string a) {
  unordered_map<char, int> m;
  int ans = 0, s = 0, e = 0;
  
  while (s < a.length() && e < a.length()) {
    unordered_map<char, int>::iterator it = m.find(a[e]);

    if (it != m.end()) {
      if (e - s > ans) ans = e - s;

      s = it->second + 1;
      e = s;
      m.clear();
    }
    else {
      m.insert(make_pair(a[e], e));
      e++;
    }
  }
  
  return max(e - s, ans);
}

int main() {
  // string a = "bbb";
  string a = "abcadefg";

  int l = lengthOfLongestSubstring(a);

  cout << "Answer for " << a << " : ";
  cout << l << "\n";

  return 0;
}