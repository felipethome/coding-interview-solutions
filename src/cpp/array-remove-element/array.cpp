/*
 * Given an array and a value. Remove all the intances of that value from the
 * array and return the new length.
 *
 * Example:
 * If the array is [4, 1, 1, 2, 1, 3] and value 1
 * New legnth will be 3. [4, 2, 3]
 *
 * Time complexity: O(N), where n is the array size.
 * Explanation: You need to have a pointer that you increment each time
 * you find an element that is different from value. And each time that occurs
 * you actually assign to the previous pointed element the element you just
 * found that is different from value.
 */

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &a, int b) {
  int count = 0;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b) continue;

    a[count] = a[i];
    count++;
  }
  
  return count;
}

int main() {
  vector<int> v = { 2, 3, 1, 1, 3, 2 };
  int newSize = removeElement(v, 2);

  for (int i = 0; i < newSize; i++) {
    cout << v[i] << ' ';
  }

  return 0;
}