/*
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Observation: the queen can move forward, backward, sideways and diagonally.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * [
 *   [".Q..",  // Solution 1
 *    "...Q",
 *    "Q...",
 *    "..Q."],
 *
 *   ["..Q.",  // Solution 2
 *    "Q...",
 *    "...Q",
 *    ".Q.."]
 * ]
 *
 * Time complexity: O(N^N to C*N!), where N is the board size.
 *
 * Explanation: we will have N lines in our chess board. Each queen needs to
 * be at one of these lines, and no more than one can be at the same line.
 * So we iterate over all columns and we keep track of the line we are currently
 * at with a variable in our function signature. While we are iterating over the
 * columns we try to fit the queen in that particular position (notice, we need
 * to have a function that is able to do that based on the current state of our
 * board) and when the queen can be positioned there we call our function again
 * with our new board state. When our function returns it is important that we
 * reinstall the previous state of the board in that call so our loop can try
 * to find a new position for that queen.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string emptyLine(int n) {
  char *c = new char[n + 1];
  int i;

  for (i = 0; i < n; i++) {
    c[i] = '.';
  }
  c[i] = '\0';

  return string(c);
}

bool check(int n, int c, vector<string> &curr) {
  int line = curr.size();

  if (line == 0) return true;
  if (line >= n) return false;

  for (int i = 0; i < curr.size(); i++) {
    int ld = c - line + i;
    int rd = c + line - i;

    if ((ld >= 0 && curr[i][ld] == 'Q') || (rd < n && curr[i][rd] == 'Q') ||
      curr[i][c] == 'Q') {
      return false;
    }
  }

  return true;
}

void solve(int n, int l, vector<string> &curr, vector<vector<string>> &ans) {
  if (l >= n) {
    ans.push_back(curr);
    return;
  }

  for (int c = 0; c < n; c++) {
    if (check(n, c, curr)) {
      string line = emptyLine(n);
      line[c] = 'Q';

      curr.push_back(line);
      solve(n, l + 1, curr, ans);
      curr.pop_back();
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<string> curr;
  
  if (n > 0) solve(n, 0, curr, ans);

  return ans;
}

int main() {
  int a;

  cout << "Enter chess board size: ";
  cin >> a;
  cout << "\n";
  vector<vector<string>> r = solveNQueens(a);

  cout << "Answer for " << a << " has " << r.size() << " elements:" << '\n';
  for (int i = 0; i < r.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
      if (j != r[i].size() - 1) cout << "  ";
    }
    cout << "]" << '\n';
  }

  return 0;
}