/**
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n^2 in spiral order.
 * 
 * Example:
 * 
 * Given n = 3,
 * You should return the following matrix:
 *  [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
 *
 * Time complexity: O(N), where N is the number of elements in the matrix.
 *
 * Explanation: You have four possible directions you need to follow and in
 * this order: right, bottom, left, top. So we create a variable to control the
 * direction (an integer from 0 to 3). We also have four limits (walls) that we
 * need to update: top = 0, left = 0, bottom = a.size(), right = a[0].size(),
 * being "a" the matrix. Our top and left increased, and our bottom and right
 * decreases until we are at the center of the matrix and top becomes equal
 * bottom and left equal right.
 * Notice right is equal to a[0].size() and not a.size(), that is because the
 * number of columns may be different from the number of lines.
 * In this exercise a.size() = a[0].size().
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
  if (n <= 0) return vector<vector<int>>();

  vector<vector<int>> result(n, vector<int>(n, 0));
  
  int t = 0, l = 0, b = n - 1, r = n - 1;
  int dir = 0, value = 1;
  
  while (t <= b && l <= r) {
    if (dir == 0) {
      for (int i = l; i <= r; i++) result[t][i] = value++;
      t++;
    }
    else if (dir == 1) {
      for (int i = t; i <= b; i++) result[i][r] = value++;
      r--;
    }
    else if (dir == 2) {
      for (int i = r; i >= l; i--) result[b][i] = value++;
      b--;
    }
    else if (dir == 3) {
      for (int i = b; i >= t; i--) result[i][l] = value++;
      l++;
    }
    
    dir = (dir + 1) % 4;
  }
  
  return result;
}

int main() {
  // int a = 1;
  // int a = 2;
  // int a = 3;
  int a = 5;
  vector<vector<int>> r = generateMatrix(a);

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