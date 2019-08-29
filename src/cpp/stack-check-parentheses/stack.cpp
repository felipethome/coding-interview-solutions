/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid, but "(]" and "([)]" are not.
 *
 * Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
 *
 * Time complexity: O(N), where N is the length of the string.
 *
 * Explanation: Just use a stack to keep the openning characters: '(', '[', '{'.
 * When you find a closing character, pop() one character from the stack and
 * see if they match (a '(' from the stack matches with a ')', etc). If the
 * stack is empty and you iterated over the entire string you have a valid
 * string.
 */

#include <iostream>
#include <stack>

using namespace std;

int isValid(string a) {
  stack<char> s;
  
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
      s.push(a[i]);
    }
    else {
      if (s.size()) {
        char c = s.top();
        if (c == '(' && a[i] != ')') return 0;
        if (c == '[' && a[i] != ']') return 0;
        if (c == '{' && a[i] != '}') return 0;
        s.pop();
      }
      else {
        return 0;
      }
    }
  }
  
  if (s.size() == 0) return 1;
  else return 0;
}

int main() {
  string a = "((({{{[[[]]]}}})))";
  
  cout << a << '\n';

  int v = isValid(a);

  if (v) cout << "Is valid." << '\n';
  else cout << "Not valid." << '\n';

  return 0;
}