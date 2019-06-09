/**
 * Given a string S, find the longest palindromic substring in S.
 * 
 * Substring of string S:
 * S[i...j] where 0 <= i <= j < len(S)
 * 
 * Palindrome string:
 * A string which reads the same backwards. More formally, S is palindrome if
 * reverse(S) = S.
 * 
 * Incase of conflict, return the substring which occurs first ( with the least
 * starting index ).
 * 
 * Example:
 * 
 * Given "aaaabaaa"
 * Output "aaabaaa"
 *
 * Time complexity: O(N^2), where N is the length of the string.
 * Space complexity: O(1).
 *
 * Explanation: we expand from the center of the palindrome, because from its
 * extremes would result in a lot of useless work. For example, if we are
 * checking the string "abad" if we expand from the extremes we would check
 * "a" with "d" and see it is not a palindrome, then "a" with "a". So, we can
 * see that if we start from the center the check of "a" with "d" would be
 * unnecessary.
 *
 * In my code I decided to run a loop from 0 .. 2 * N - 1, this is because
 * there are two cases:
 *
 * 1. When our palindrome will have odd length and then the center itself is
 * made of just one character and doesn't need to be checked
 * 2. When the palindrome length will be even and the we check the center with
 * its right neighbor. For example "bbbb", when we are at index 1 as center
 * we compare a[1] with a[2].
 *
 * So I iterate double of the length of the string and for odd i I defined I'm
 * in the case where the palindrome has even length. The center will always be
 * i / 2.
 */

#include <iostream>

using namespace std;

string longestPalindrome(string a) {
  int n = a.size(), start = 0, end = 0;

  for (int i = 0; i < 2 * n - 1; i++) {
    int center = i / 2, currStart = 0, currEnd = 0;
    // If i is odd I consider the palindrome to have even length.
    int left = i % 2 ? center : center - 1, right = center + 1;

    while (left >= 0 && right < n && a[left] == a[right]) {
      currStart = left;
      currEnd = right;
      left--;
      right++;
    }

    // Just "larger", and not "larger or equal" because we want to preserve the
    // palindrome that starts at the lowest possible index.
    if (currEnd - currStart > end - start) {
      start = currStart;
      end = currEnd;
    }
  }

  return a.substr(start, (end - start) + 1);
}

int main() {
  // string a = "";
  // string a = "a";
  // string a = "aaa";
  // string a = "bbbb";
  // string a = "abb";
  string a = "aaaabaaa";

  string r = longestPalindrome(a);

  cout << r << endl;

  return 0;
}