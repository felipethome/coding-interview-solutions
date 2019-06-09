/**
 * Given numRows, generate the first numRows of Pascal’s triangle.
 * Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from
 * previous row R - 1.
 * 
 * Example:
 * Given numRows = 5,
 * 
 * Return
 * 
 * [
 *      [1],
 *      [1,1],
 *      [1,2,1],
 *      [1,3,3,1],
 *      [1,4,6,4,1]
 * ]
 *
 * Explanation: the first and last elements of every row are always one. The
 * others you just calculate using the above formula. Just the first row that
 * is [1] needs to be placed manually in your answer, so start with it and then
 * use the formula.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int n) {
  vector<vector<int>> ans;
  
  if (n >= 1) {
    vector<int> row(1, 1);
    ans.push_back(row);
  }
  
  for (int i = 1; i < n; i++) {
    vector<int> row;
    row.push_back(1);
    for (int j = 1; j <= i - 1; j++) {
      row.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
    }
    row.push_back(1);
    ans.push_back(row);
  }
  
  return ans;
}

int main() {
  int a = 22;
  vector<vector<int>> r = generate(a);

  cout << "Answer: " << endl;
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  cout << "Last line sum:" << endl;
  int sum = 0;
  for (int i = 0; i < r[r.size() - 1].size(); i++) {
    sum += r[r.size() - 1][i];
  }
  cout << sum << endl;

  return 0;
}