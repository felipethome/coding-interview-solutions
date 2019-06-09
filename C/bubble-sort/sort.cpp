#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &a) {
  int temp;
  bool sorted = true;

  for (int i = 0; i < a.size(); i++) {
    // The largest element in one complete execution of the inner loop will
    // be in its final position. Then, the element before the last in the
    // second complete execution and so on. That is why we subtract i, so we
    // don't take into consideration elements that are already in their final
    // position.
    for (int j = 0; j < a.size() - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        sorted = false;
      }
    }

    // If there were no swaps, so the list is already sorted
    if (sorted) break;
    sorted = true;
  }
}

int main() {
  vector<int> a = {1, 3, 2, 5, 4, 7, 8, 9, 6};

  bubbleSort(a);

  for (int e : a) cout << e << " ";
  cout << endl;

  return 0;
}