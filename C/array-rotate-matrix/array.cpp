/**
 * You are given an n x n 2D matrix representing an image. Rotate the image by
 * 90 degrees (clockwise). You need to do this in place.
 * 
 * 
 * Example:
 * 
 * If the array is
 * [
 *     [1, 2],
 *     [3, 4]
 * ]
 * Then the rotated array becomes
 * [
 *     [3, 1],
 *     [4, 2]
 * ]
 *
 * Time complexity: O(N), where N is the number of elements in the matrix.
 * Space complexity: O(1).
 *
 * Explanation: they way I initially did was to swap all the elements symmetric
 * in the matrix diagonal, then in another loop swap all the elements symmetric
 * in the line.
 * There is a easier way. Suppose you have the matrix:
 *
 * a11 a12 a13 a14
 * a21 a22 a23 a24
 * a31 a32 a33 a34
 * a41 a42 a43 a44
 *
 * We can make:
 * #1
 * temp = a11
 * a11 = a41
 * a41 = a44
 * a44 = a14
 * a14 = temp
 *
 * #2
 * temp = a12
 * a12 = a31
 * a31 = a43
 * a43 = a24
 * a24 = temp
 *
 * and so on.
 *
 * To complete the rotation with this process we need to go until line N / 2,
 * not including N / 2, and start at column i (where i is the line) and go until
 * column N - i - 1, not including column N - i - 1. So, in the above example,
 * we would perform this process for lines 0 and 1, and for line 0 we would go
 * from column 0 to 2 (included), and for line 1 we would use just column 1.
 */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &a) {
  int n = a.size();

  for (int i = 0; i < n / 2; i++) {
    for (int j = i; j < n - i - 1; j++) {
      int temp = a[i][j];
      a[i][j] = a[n - j - 1][i];
      a[n - j - 1][i] = a[n - i - 1][n - j - 1];
      a[n - i - 1][n - j - 1] = a[j][n - i - 1];
      a[j][n - i - 1] = temp;
    }
  }
}

// void rotate(vector<vector<int>> &a) {
//   int n = a.size();

//   // Swap elements symmetric to the diagonal.
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < i; j++) {
//       swap(a[i][j], a[j][i]);
//     }
//   }

//   // Swap elements symmetric in a line.
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n / 2; j++) {
//       swap(a[i][j], a[i][n - j - 1]);
//     }
//   }
// }

int main() {
  vector<vector<int>> a = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  rotate(a);

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}