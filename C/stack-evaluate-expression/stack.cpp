/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Example:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 * Time complexity: O(N), where N is the size of the array.
 * Explanation: Use a stack to store the integers. Each time you find a operand
 * use your stack to make the operation. Store the result of the operation at
 * the top of the stack. This way, the top of the stack os always your right
 * operand and the element before the top is your left operand. Once you process
 * all the array the stack must be left with just one element that is your
 * answer, so return the top of the stack.
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int _eval(int l, int r, string o) {
  int res = 0;

  if (o == "*") {
    res = l * r;
  }
  else if (o == "/") {
    res = l / r;
  }
  else if (o == "+") {
    res = l + r;
  }
  else if (o == "-") {
    res = l - r;
  }

  return res;
}

int evalRPN(vector<string> &a) {
  if (a.size() == 1) return atoi(a[0].c_str());

  stack<int> s;
  int l, r;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != "*" && a[i] != "/" && a[i] != "+" && a[i] != "-") {
      s.push(atoi(a[i].c_str()));
    }
    else {
      r = s.top();
      s.pop();
      l = s.top();
      s.pop();
      s.push(_eval(l, r, a[i]));
    }
  }

  return s.top();
}

int main() {
  vector<string> a = {"4", "13", "5", "2", "*", "/", "+"};
  // vector<string> a = {"2", "1", "+", "3", "*"};
  // vector<string> a = {"4", "13", "5", "/", "+"};
  // vector<string> a = {"2", "2", "/"};
  // vector<string> a = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ' ';
    
  }
  
  cout << '\n';

  int r = evalRPN(a);
  
  cout << "Answer: " << r << '\n';

  return 0;
}