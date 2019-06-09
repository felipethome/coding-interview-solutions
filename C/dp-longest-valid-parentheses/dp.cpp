/**
 * Given a string containing just the characters '(' and ')', find the length of
 * the longest valid (well-formed) parentheses substring.
 *
 * Example:
 * For "(()", the longest valid parentheses substring is "()", which has
 * length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is
 * "()()", which has length = 4.
 *
 * Time complexity: O(N), where N is the length of the string.
 * Space complexity: O(N).
 *
 * Explanation: there are two ways that I know to solve this exercise. One, uses
 * a stack, the other one, dynamic programming. First of all, notice that it is
 * simple to know if the sequence is valid with a stack, but find out the length
 * of the sequence using the stack approach is trickier.
 *
 * Initialize a dp variable with the size as the length of the string and 0 as
 * the initial values. For each parenthesis in the input string we check if it
 * is a closing parenthesis ')', because if it is we need to check if it is part
 * of a valid sequence and update the dp variable with the length of this valid
 * sequence. To do that we need to identify the opening parenthesis of this
 * sequence and (if this opening parenthesis exist) sum with the length of the
 * valid sequence we found previously to this opening parenthesis. Notice, that
 * for each valid parenthesis pair we add 2, because they are composed by two
 * characters ('(' and ')'). For example:
 *      0 1 2 3 4 5 6
 *  s = ( ( ( ) ( ) )
 * dp = 0 0 0 0 0 0 0
 * At s[3] we have a ')', so we get the opening parenthesis using the length
 * of the valid sequence we had before s[3], or in other words, we get the value
 * of dp[2]. In this case is 0, so the opening parenthesis for s[3] should be at
 * s[2], which is in fact a '(' making a valid pair, so we add dp[2] + 2. Then,
 * we add the length of the valid sequence we had before s[2], dp[1], which is
 * again 0. We get:
 *      0 1 2 3 4 5 6
 * dp = 0 0 0 2 0 0 0
 * At s[5] we have again a ')', so we get the opening parenthesis checking the
 * length of dp[4], which is 0, hence the opening parenthesis for s[5] should be
 * at s[4], which is in fact a '(', so we do dp[4] + 2. Now, we add the length
 * of the sequence prior to the opening parenthesis, which is dp[3] = 2. We get:
 *      0 1 2 3 4 5 6
 * dp = 0 0 0 2 0 4 0
 * Repeating the process at s[6], we get:
 *      0 1 2 3 4 5 6
 * dp = 0 0 0 2 0 4 6
 *
 * Return the maximum value of the dp variable.
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int longestValidParentheses(string a) {
  vector<int> dp(a.size(), 0);
  int ans = 0;

  for (int i = 1; i < a.size(); i++) {
    int opening = i - (dp[i - 1] + 1);
    if (opening >= 0 && a[i] == ')' && a[opening] == '(') {
      dp[i] = dp[i - 1] + 2 + (opening - 1 >= 0 ? dp[opening - 1] : 0);
    }
    ans = max(ans, dp[i]);
  }

  return ans;
}

// // This solution uses a stack and is also O(N) time.
// int longestValidParentheses(string a) {
//   // Create a stack and push -1 as initial index to it.
//   stack<int> stk;
//   stk.push(-1);

//   // Initialize ans
//   int ans = 0;

//   // Traverse all characters of given string
//   for (int i = 0; i < a.size(); i++) {
//     // If opening bracket, push index of it
//     if (a[i] == '(') stk.push(i);
//     else { // If closing bracket, i.e.,a[i] = ')'
//       // Pop the previous opening bracket's index
//       stk.pop();

//       // Check if this length formed with base of
//       // current valid substring is more than max 
//       // so far
//       if (!stk.empty()) ans = max(ans, i - stk.top());
//       // If stack is empty. push current index as 
//       // base for next valid substring (if any)
//       else stk.push(i);
//     }
//   }

//   return ans;
// }

int main() {
  // string a = "";
  // string a = ")";
  // string a = "(";
  // string a = ")(";
  // string a = "()";
  // string a = "((()))";
  // string a = "((()())";
  // string a = "(()";
  // string a = ")()()";
  // string a = "((()";
  // string a = ")()())";
  // string a = "()(()))))";
  // string a = "(()(((()()(()((()()))(())()))";
  string a = "()())((((((()))))))))(()))())(()((()))))(((((";

  int m = longestValidParentheses(a);

  cout << "m: " << m << endl;

  return 0;
}