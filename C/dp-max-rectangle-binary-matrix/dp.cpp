/**
 * Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle
 * containing all ones and return its area.
 * 
 * Bonus if you can solve it in O(n^2) or less.
 * 
 * Example:
 * A = [
 *        1 1 1
 *        0 1 1
 *        1 0 0 
 *     ]
 *
 * Output 4 as the max area rectangle is created by the 2x2 rectangle created
 * by (0,1), (0,2), (1,1) and (1,2).
 *
 * Time complexity: O(N^2), where N is the number of elements in the matrix.
 * Space complexity: O(N).
 *
 * Explanation: first thing we need is a matrix telling us the maximum number
 * of consecutive 1's to the left of our current element, including the element
 * (call this matrix "c"). I also used a matrix that tells me exactly how many
 * consecutive 1's we have above the current element, including the current
 * element, though this matrix is not necesary (see note 1). Now we iterate over
 * our elements and for each element that is a 1 we check what is the maximum
 * area of the rectangles that have this element as their bottom right corner.
 * Calculate this area is simple, start from the row with the element and start
 * to go up, incrementing your height by 1 every time. The width of the
 * rectangle is the min between the previous calculated width and the value you
 * can found in your matrix "c" for the same column of your element and the row
 * you are currently checking.
 * Note1: You don't need this matrix of consecutives 1 in the y-direction
 * because you could just go until you are at row with index 0 or when the
 * column of your element at the row you are at is 0 (a[i - y][j] == 0), because
 * this means it is impossible to find another rectangles that have the element
 * a[i][j] as the bottom right corner.
 * Note 2: After calculating the matrix of consecutive 1's in the x-direction
 * you could apply the algorithm of "max rectangle area in a histogram" to find
 * the answer.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<int>> &a) {
  if (a.size() == 0 || a[0].size() == 0) return 0;

  int area = 0;
  vector<vector<int>> r(a.size(), vector<int>(a[0].size(), 0));
  vector<vector<int>> c(a.size(), vector<int>(a[0].size(), 0));

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      if (a[i][j]) {
        c[i][j] = j - 1 >= 0 ? 1 + c[i][j - 1] : 1;
        r[i][j] = i - 1 >= 0 ? 1 + r[i - 1][j] : 1;

        int y = 1, x = a[0].size();
        while (y <= r[i][j]) {
          x = min(x, c[i - (y - 1)][j]);
          area = max(area, x * y);
          y++;
        }
      }
    }
  }

  return area;
}

int main() {
  // vector<vector<int>> a = {
  //   {1},
  // };
  
  // vector<vector<int>> a = {
  //   {0, 1},
  //   {1, 0},
  // };

  // vector<vector<int>> a = {
  //   {1, 1, 1},
  //   {0, 1, 1},
  //   {1, 0, 0},
  // };

  vector<vector<int>> a = {
    {0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1}
  };

  int m = maximalRectangle(a);

  cout << "max: " << m << endl;

  return 0;
}