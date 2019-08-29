/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
 * You are given a target value to search. If found in the array, return its
 * index, otherwise return -1.
 * 
 * Notes:
 * 1. You may assume no duplicate exists in the array.
 * 2. Think about the case when there are duplicates. Does your current solution
 * work? How does the time complexity change?
 *
 * Example:
 * 
 * Input = [4 5 6 7 0 1 2] and target = 4
 * Output = 0
 *
 * Time complexity: O(logN), where N is the size of the input array.
 * Space complexity: O(1).
 *
 * Explanation: the trick is to use a normal binary search but "rotate" the
 * just calculated middle point. So, we find the rotation point (the index
 * of the minimum element in the array) and after we perform a normal binary
 * search, with normal low, high and middle points, but when we will efective
 * access a the middle element we add the rotation index:
 * a[mid] becomes a[(mid + n) % n].
 *
 * Notice that finding the rotation point (minimum element) is also a O(logN)
 * operation. You can find details of how to write this algorithm in the code
 * below.
 */

#include <iostream>
#include <vector>

using namespace std;

// Find the minimum element in a sorted array using binary search.
int findMin(vector<int> &a) {
  int n = a.size(), low = 0, high = n - 1;

  while (low <= high) {
    // If the low element is smaller than the high element so the piece of array
    // we are current looking at is not rotated so we can return low as the
    // minimum element.
    if (a[low] <= a[high]) return low;

    int mid = (low + high) / 2;
    int prev = (mid - 1 + n) % n;
    int next = (mid + 1) % n;

    // If the previous and next element are smaller than the middle one we
    // found the minimum element in the array.
    if (a[mid] <= a[prev] && a[mid] <= a[next]) return mid;

    // If middle element is smaller than high element so we know that all
    // elements after the middle one will continue to increase. So, we discard
    // this part.
    if (a[mid] <= a[high]) high = mid - 1;
    // If the middle element is larger than low element (and we know the array
    // is rotated and we also know we still not found the minimum element), so
    // we can affirm the minimum element will be behind the middle element.
    else if (a[mid] >= a[low]) low = mid + 1;
  }

  return -1;
}

int search(vector<int> &a, int b) {
  int n = a.size(), low = 0, high = n - 1, rotation = findMin(a);

  while (low <= high) {
    int mid = (low + high) / 2;

    if (a[(mid + rotation) % n] == b) return (mid + rotation) % n;

    if (a[(mid + rotation) % n] < b) low = mid + 1;
    else high = mid - 1;
  }

  return -1;
}

int main() {
  vector<int> a = {6, 7, 1, 2, 3, 4, 5};
  int b = 4;

  int r = search(a, b);

  cout << r << endl;

  return 0;
}