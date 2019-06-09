/**
 * Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row
 * and column to 0. Do it in place. Note that this will be evaluated on the
 * extra memory used. Try to minimize the space and time complexity.
 * 
 * Example:
 * 
 * Given array A as
 * 1 0 1
 * 1 1 1 
 * 1 1 1
 * On returning, the array A should be :
 * 0 0 0
 * 1 0 1
 * 1 0 1
 *
 * Time complexity: O(N), where N is the number of elements in the matrix.
 * Space complexity: O(1).
 *
 * Explanation: use the first row and column to store which rows and columns
 * beside the first ones needs to be set to 0. Since you will use the first
 * row and column to store information you need to check if they have 0's before
 * starting to overwrite their information. After, with the information you
 * stored you set the rows and columns to 0. Finally, if you checked that the
 * first row and column used to have zeros you need to also set them to 0.
 *
 * Notice you don't need to restore the information of the first row/column
 * because if you made one of its elements 0 it is because that row/column needs
 * to be set entirely to 0 including the first row/column.
 *
 * You could use an intermediary symbol, like the number 2, to mark columns and
 * rows that need to be shifted to 0, but the complexity wouldn't be linear
 * because you would end up repeating the work. 
 */

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &a) {
  if (a.size() == 0 || a[0].size() == 0) return;
  
  int nrows = a.size(), ncols = a[0].size();
  bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

  // Does first row have zero?
  for (int j = 0; j < ncols; ++j) {
    if (a[0][j] == 0) {
      hasZeroFirstRow = true;
      break;
    }
  }

  // Does first column have zero?
  for (int i = 0; i < nrows; ++i) {
    if (a[i][0] == 0) {
      hasZeroFirstColumn = true;
      break;
    }
  }

  // find zeroes and store the info in first row and column
  for (int i = 1; i < nrows; ++i) {
    for (int j = 1; j < ncols; ++j) {
      if (a[i][j] == 0) {
        a[i][0] = 0;
        a[0][j] = 0;
      }
    }
  }

  // set zeroes except the first row and column
  for (int i = 1; i < nrows; ++i) {
    for (int j = 1; j < ncols; ++j) {
      if (a[i][0] == 0 || a[0][j] == 0)  a[i][j] = 0;
    }
  }

  // set zeroes for first row and column if needed
  if (hasZeroFirstRow) {
    for (int j = 0; j < ncols; ++j) a[0][j] = 0;
  }
  if (hasZeroFirstColumn) {
    for (int i = 0; i < nrows; ++i) a[i][0] = 0;
  }
}

int main() {
  vector<vector<int>> a = {
    {1, 0, 1},
    {1, 1, 1},
    {1, 1, 1},
  };

  setZeroes(a);

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}