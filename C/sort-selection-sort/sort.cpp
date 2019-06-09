/**
 * Selection Sort Algorithm.
 *
 * Time complexity: O(N^2), where N is the size of the array to be sorted.
 * Space complexity: O(1).
 *
 * Explanation: for each index i (0..N - 1) we look for the minimum element
 * after this index. Then, we swap a[i] with a[min].
 */

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &a) {
  for (int i = 0; i < a.size() - 1; i++) {
    int min = i;

    for (int j = i + 1; j < a.size(); i++) {
      if (a[j] < a[min]) min = j;
    }

    if (min != i) swap(a[min], a[i]);
  }
}

int main() {
  vector<int> a = {1, 3, 2, 5, 4, 7, 8, 9, 6};

  selectionSort(a);

  cout << endl;
  for (int e : a) cout << e << " ";
  cout << endl;

  return 0;
}