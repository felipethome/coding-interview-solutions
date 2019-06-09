/**
 * You are in an infinite 2D grid where you can move in any of the 8 directions:
 * (x,y) to 
 * (x+1, y), 
 * (x - 1, y), 
 * (x, y+1), 
 * (x, y-1), 
 * (x-1, y-1), 
 * (x+1,y+1), 
 * (x-1,y+1), 
 * (x+1,y-1) 
 * 
 * You are given a sequence of points and the order in which you need to cover
 * the points. Give the minimum number of steps in which you can achieve it.
 * You start from the first point.
 * 
 * Example:
 * Input [(0, 0), (1, 1), (1, 2)]
 * Output 2
 * It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move
 * from (1, 1) to (1, 2).
 *
 * Time complexity: O(N), where N is the number of points.
 *
 * Explanation: you just need to realize that since you can move diagonally
 * that the minimum distance from one point to another will always be the
 * max(abs(x1 - x2), abs(y1 - y2)) because the diagonals allow you to behave
 * like if you were moving horizontally or vertically to achive the point. For
 * example, suppose we want to know the minimum distance of (0, 0) to (1, 3).
 * Before calculating this distance imagined you wanted to go from point
 * (0, 0) to (0, 3). The minimum distance in this case would be 3 because we
 * just need to walk horizontally until the final point. In our original case
 * the final point is not at the same line or column so we need to wak
 * diagonally. And when we do, we increase x by one and y by one, so it is like
 * if we were in a case where we are at the same line or column of the origin
 * point. It is difficult to explain, but easy to realize if you draw the grid.
 */

#include <iostream>
#include <vector>

using namespace std;

int coverPoints(vector<int> &x, vector<int> &y) {
  int n = x.size(), ans = 0;

  for (int i = 1; i < x.size(); i++) {
    ans += max(abs(x[i] - x[i - 1]), abs(y[i] - y[i - 1]));
  }

  return ans;
}

int main() {
  // vector<int> x = {0, 1, 1};
  // vector<int> y = {0, 1, 2};

  vector<int> x = {0, 4};
  vector<int> y = {0, 5};

  int m = coverPoints(x, y);

  cout << "m: " << m << endl;

  return 0;
}