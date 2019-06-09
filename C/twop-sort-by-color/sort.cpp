/*
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue. Here, we will use the integers 0, 1, and 2 to represent the
 * color red, white, and blue respectively.
 *
 * Example:
 * Input : [0 1 2 0 1 2]
 * Modify array so that it becomes : [0 0 1 1 2 2]
 *
 * Time complexity: O(N), where N is the length of the array.
 *
 * Explanation: Keep a counter to each color. Then overwrite the array using the
 * counter. For example, if one of the counter is named red_counter. Decrement
 * the red counter and assign 0 (the integer representing the red color) to the
 * array. Another approach is, swap the 0s to the beginning of the array
 * keeping a pointer and 2s the the end also keeping a pointer. 1s will
 * automatically be at the right place.
 */

#include <iostream>
#include <vector>

void sortColors(vector<int> &a) {
  int cr = 0, cw = 0, cb = 0, i = 0;
  
  if (a.size() == 1) return;
  
  while (i < a.size()) {
    if (a[i] == 0) cr++;
    else if (a[i] == 1) cw++;
    else cb++;
    i++;
  }
  
  i = 0;
  
  while (cr--) {
    a[i] = 0;
    i++;
  }
  
  while (cw--) {
    a[i] = 1;
    i++;
  }
  
  while (cb--) {
    a[i] = 2;
    i++;
  }
}

int main() {
  vector<int> v1 = { 0, 1, 2, 0, 1, 2 };
  vector<int> r = sortColors(v);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << ' ';
  }

  return 0;
}