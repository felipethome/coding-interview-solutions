/**
 * Given an array ‘A’ of sorted integers and another non negative integer k,
 * find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 *
 * Example:
 * A : [1 3 5] 
 * k : 4
 *
 * Output : True, because 5 - 1 = 4
 *
 * Time complexity: O(N), where N is the size of the array.
 *
 * Explanation: Start with a pointer at the beginning of the array, call it i,
 * and another one at beginning + 1, call it j. Make the diff between these two
 * elements, if the diff is bigger than k so we increment j, otherwise we
 * increment i.
 */

#include <stdio.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int diffPossible(int* a, int n1, int k) {
  int i = 1, j = 0, diff;

  while (i != j && i < n1 && j < n1) {
    diff = a[i] - a[j];
    
    if (diff > k && j + 1 != i) j++;
    else if (diff > k && j + 1 == i) {j++; i++;}
    else if (diff < k) i++;
    else return 1;
  }

  return 0;
}

int main() {
  int v[7] = {3, 5, 6, 10, 11, 13, 14};
  int diffExists = diffPossible(v, 7, 5);

  if (diffExists) printf("\nThe diff is possible\n");
  else printf("\nThe diff is not possible\n");

  return 0;
}