/**
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than floor(n/2) times.
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example:
 * Given [2, 1, 2], return 2, which occurs 2 times which is greater than 3/2.
 *
 * Time complexity: O(N), where N is the size of the array.
 * Space complexity: O(1).
 *
 * Explanation: it can be done easily in O(N^2), where you count each element
 * to see if the number of repetitions is bigger than n / 2, but instead of this
 * brute force approach you should use Moore's Voting Algorithm.
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &a) {
  int count = 1, elem = a[0];
  
  for (int i = 1; i < a.size(); i++) {
    count = elem == a[i] ? count + 1 : count - 1;
    if (count == 0) {
      elem = a[i];
      count = 1;
    }
  }
  
  return elem;
}

int main() {
  vector<int> a = {1, 1, 3, 4, 4, 4, 6, 4, 1, 4, 7, 4, 4};

  int m = majorityElement(a);

  cout << "m: " << m << endl;

  return 0;
}