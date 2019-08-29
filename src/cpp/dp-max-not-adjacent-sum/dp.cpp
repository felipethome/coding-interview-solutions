/**
 * Given a 2 * N Grid of numbers, choose numbers such that the sum of the
 * numbers is maximum and no two chosen numbers are horizontally, vertically or
 * diagonally adjacent, and return it.
 *
 * Example:
 * Given the grid
 *   1 2 3 4
 *   2 3 4 5
 * Return 8, because we choose 3 and 5 so sum will be 8.
 *
 * Time complexity: O(N), where N is the number of columns of the grid.
 * Space complexity: O(1).
 *
 * Explanation: first you need to realize that not get an element adjacent to
 * another in this problem means that for a chosen element you can only get
 * another element after the next column of this chosen element, or in other
 * words, you need to have one column of space between chosen elements. Second,
 * at each column we are at the element that matters to us is always the largest
 * one. Third, lets see with an example how we can reuse previous calculated
 * information to get our answer:
 * Given,
 * 9, 12, 4, 10, 8, 11
 * 4, 6, 13, 24, 1, 15
 *
 * Create an empty array with the number of columns of the grid, call it b.
 *
 * At the beginning, we look at the first column and since this array we created
 * is empty we store into it max(9, 4), which is 9. After, at the second
 * position we store max(9, 12, 6), which is 12.
 *
 * So right now we have: 9 12 _ _ _ _
 *
 * Now, at the third column we can realize our first sum. So, we check if 9 +
 * max(13, 4) is bigger than 12, and it is, so we store 9 + 13: 9 12 22 _ _ _
 *
 * At the fourth column we again use the previous information stored in the
 * array to get our largest sum. We check max(10, 24) + 12 > 22, and it is, so
 * we store 24 + 12: 9 12 22 36 _ _
 * And we keep doing that until we checked the entire grid.
 * 
 * What we are doing is: if we already calculated what is the largest sum for,
 * lets suppose our 3 first columns, when looking at the fourth column we know
 * that we already know the largest sum for 2 and 3 first columns, so we check
 * if using the maximum element of the fourth column with the largest sum for
 * the 2 first columns is larger than the sum for the first 3 columns. If it is
 * not we just propagate the sum of the first 3 columns.
 *
 * Notice we can use constant space, because instead of this array we can just
 * use variables to keep the two last sums we calculated.
 */

#include <iostream>
#include <vector>

using namespace std;

int adjacent(vector<vector<int>> &a) {
  if (a.size() == 0 || a[0].size() == 0) return 0;

  int m, s1 = 0, s2 = 0;

  for (int i = 0; i < a[0].size(); i++) {
    int curr = max(a[0][i], a[1][i]);

    if (curr + s1 >= s2) {
      int temp = s1;
      s1 = s2;
      s2 = curr + temp;
    }
    else {
      s1 = s2;
    }
  }

  return s2;
}

int main() {
  vector<vector<int>> a;

  // vector<int> b = {16};
  // vector<int> c = {31};
  
  // vector<int> b = {16, 32};
  // vector<int> c = {31, 5};

  vector<int> b = {1, 2, 3, 4};
  vector<int> c = {2, 3, 4, 5};
  
  // vector<int> b = {9, 12, 4, 10, 8, 11};
  // vector<int> c = {4, 6, 13, 24, 1, 15};
  
  // vector<int> b = {16, 5, 54, 55};
  // vector<int> c = {31, 30, 36, 70};

  a.push_back(b);
  a.push_back(c);

  int m = adjacent(a);

  cout << "max: " << m << endl;

  return 0;
}