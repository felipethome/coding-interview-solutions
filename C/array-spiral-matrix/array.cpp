/**
 * Given a matrix of m * n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example:
 * Given the following matrix:
 * 
 * [
 *     [ 1, 2, 3 ],
 *     [ 4, 5, 6 ],
 *     [ 7, 8, 9 ]
 * ]
 *
 * You should return: [1, 2, 3, 6, 9, 8, 7, 4, 5]
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
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &a) {
  vector<int> result;
  
  if (a.size() == 0 || a[0].size() == 0) return result;
  
  int t = 0, b = a.size() - 1, l = 0, r = a[0].size() - 1;
  int dir = 0;
  
  while (t <= b && l <= r) {
    if (dir == 0) {
      for (int i = l; i <= r; i++) result.push_back(a[t][i]);
      t++;
    }
    else if (dir == 1) {
      for (int i = t; i <= b; i++) result.push_back(a[i][r]);
      r--;
    }
    else if (dir == 2) {
      for (int i = r; i >= l; i--) result.push_back(a[b][i]);
      b--;
    }
    else if (dir == 3) {
      for (int i = b; i >= t; i--) result.push_back(a[i][l]);
      l++;
    }
    
    dir = (dir + 1) % 4;
  }
  
  return result;
}

int main() {
  vector<vector<int>> a = {
    {1, 2},
    {3, 4},
    {5, 6}
  };
  vector<int> r = spiralOrder(a);

  cout << "Answer: " << endl;
  cout << "[ ";
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
    if (i != r.size() - 1) cout << "  ";
  }
  cout << "]" << endl;

  return 0;
}