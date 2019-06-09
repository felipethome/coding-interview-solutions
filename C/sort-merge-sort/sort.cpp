#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int s, int m, int e) {
  int i, j, k, n1 = m - s + 1, n2 =  e - m;
  vector<int> L(n1), R(n2);

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++) L[i] = a[s + i];
  for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

  /* Merge the temp arrays back into a[s..e]*/
  i = 0;
  j = 0;
  k = s;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    }
    else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if there are any.
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if there are any.
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &a, int s, int e) {
  if (s < e) {
    // Same as (s + e) / 2, but avoids overflow for large s and e.
    int m = s + (e - s) / 2;

    // Sort first and second halves
    mergeSort(a, s, m);
    mergeSort(a, m + 1, e);

    merge(a, s, m, e);
  }
}

int main() {
  vector<int> a = {1, 3, 2, 5, 4, 7, 8, 9, 6};

  mergeSort(a, 0, a.size() - 1);

  cout << endl;
  for (int e : a) cout << e << " ";
  cout << endl;

  return 0;
}