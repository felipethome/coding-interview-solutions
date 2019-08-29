/*
 * Write a program to validate if the input string has redundant braces?
 * Return 0 / 1 , 0 -> NO 1 -> YES 
 * Input will be always a valid expression and operators allowed are only:
 * + , * , - , /
 *
 * Example:
 * ((a + b)) has redundant braces so answer will be 1
 * (a + (a + b)) doesn't have have any redundant braces so answer will be 0
 *
 * Time complexity: O(N), where N is the length of the string.
 * Explanation: All non-redundant braces must have at least one operator
 * inside of it. So we use a stack to put all the openning braces and operators.
 * Each time we find a closing brace ')' we start to pop() the stack until the
 * element in the stack is a '('. When that happens we check to see if before
 * the '(' element on the stack there were operators. If there were not we
 * return 1. When we get to the end of the string since the exercise guarantee
 * it is valid expression we just return 0.
 */

#include <iostream>
#include <stack>

using namespace std;

int braces(string a) {
  stack<char> s;

  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '(' || a[i] == '+' || a[i] == '*' || a[i] == '/'
      || a[i] == '-') {
      s.push(a[i]);
    }
    else if (a[i] == ')') {
      if (s.top() == '(') return 1;
      else {
        while (!s.empty() && s.top() != '(') {
          s.pop();
        }

        if (s.top() == '(') s.pop();
      }
    }
  }

  return 0;
}

int main() {
  // string a = "((a + b))";
  string a = "(a + (a + b))";
  // string a = "((a + b) + (a + b))";
  // string a = "((a + b - c * d) + (a - a + b))";
  
  cout << a << '\n';

  int r = braces(a);

  if (r) cout << "Redudant." << '\n';
  else cout << "Not redundant." << '\n';

  return 0;
}