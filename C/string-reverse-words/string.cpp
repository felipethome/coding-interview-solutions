/**
 * Given an input string, reverse the string word by word.
 * 
 * Notes:
 * 1. A sequence of non-space characters constitutes a word.
 * 2. Your reversed string should not contain leading or trailing spaces, even
 * if it is present in the input string.
 * 3. If there are multiple spaces between words, reduce them to a single space
 * in the reversed string.
 * 
 * Example:
 * 
 * Given s = "the sky is blue",
 * 
 * return "blue is sky the".
 *
 * Time complexity: O(M * N), where N is the length of the given string and
 * M is the length of the largest word in this string.
 * Space complexity: O(N).
 *
 * Explanation: there are multiple ways of performing this, but all are similar.
 * I decided to start at the beginning of the given string and create word by
 * word. When I find a space it is time to insert the created word in the
 * beginning of the answer (in C++ I used insert()).
 */

#include <iostream>

using namespace std;

void reverseWords(string &a) {
  string ans = "", word = "";
  int i = 0;

  while (i < a.size()) {
    // Create a word.
    if (a[i] != ' ') {
      word.push_back(a[i]);
    }
    // Found a space so insert the word in the answer.
    else if (word.size() > 0) {
      // If the answer is not empty we need to insert a space after the current
      // word, otherwise it's the last word in the answer so no space is needed.
      if (ans.size() > 0) word.push_back(' ');
      ans.insert(0, word);
      word = "";
    }
    i++;
  }

  // Insert the last word because if there is no space after it the "while"
  // loop will not insert it.
  if (word.size()) {
    if (ans.size() > 0) word.push_back(' ');
    ans.insert(0, word);
  }

  a = ans;
}

int main() {
  string a = "the sky is blue";

  reverseWords(a);

  cout << a << endl;

  return 0;
}