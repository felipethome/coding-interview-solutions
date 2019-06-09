/**
 * Given a N by N square matrix, return an array of its anti-diagonals. Look at
 * the example for more details.
 * 
 * Example:
 *     
 * Given,
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 * Return
 * [ 
 *   [1],
 *   [2, 4],
 *   [3, 5, 7],
 *   [6, 8],
 *   [9]
 * ]
 *
 * Time complexity: O(N), where N is the number of elements in the matrix.
 *
 * Explanation: your diagonals start at each element of your first row, and
 * after those, at the last element of each row after the first one. So just
 * iterate over these elements where the diagonals start and then for each one
 * print the elements in the diagonal decreasing one column and increasing one
 * row each time.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &a) {
  vector<vector<int>> ans;

  int t = 0, l = 0, dim = a.size();

  while (t < dim) {
    int ct = t, cl = l;
    vector<int> temp;

    while (ct < dim && cl >= 0) {
      temp.push_back(a[ct][cl]);
      ct++;
      cl--;
    }

    if (temp.size()) ans.push_back(temp);

    if (l == dim - 1) t++;
    else l++;
  }

  return ans;
}

int main() {
  // vector<vector<int>> a;

  // vector<vector<int>> a = {
  //   {1},
  // };

  // vector<vector<int>> a = {
  //   {1, 2},
  //   {3, 4},
  // };

  // vector<vector<int>> a = {
  //   {1, 2, 3},
  //   {4, 5, 6},
  //   {7, 8, 9}
  // };
  
  vector<vector<int>> a = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
  };

  vector<vector<int>> r = diagonal(a);

  cout << "Answer: " << endl;
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}