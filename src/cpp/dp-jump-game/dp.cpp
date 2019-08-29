/**
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array. Each element in the array represents your maximum
 * jump length at that position. Determine if you are able to reach the last
 * index.
 * 
 * Example:
 * A = [2, 3, 1, 1, 4], return 1 ( true ).
 * 
 * A = [3, 2, 1, 0, 4], return 0 ( false ).
 * 
 * Return 0/1 for this problem.
 *
 * Time complexity: O(N), where N is the size of the array.
 * Space complexity: O(1).
 *
 * Explanation: we start from the end of our array and we keep a variable that
 * tell us the minimum index in the array we need to achive to be sure we can
 * arrive at the end of the array in the end of the game (call this variable
 * minIndex). At the beginning this variable is the index of the last element.
 * We start our iteration checking the element before the last element and we
 * see if the number of maximum steps we can take is enough (this means:
 * current i + steps needs to be larger or equal) to arrive at minIndex. If it
 * is we update minIndex assigning the index of the element we just checked.
 * We keep doing this until we are at index 0 and as before we check if we can
 * arrive at minIndex, and if we can we return 1, otherwise 0.
 */

#include <iostream>
#include <vector>

using namespace std;

int canJump(vector<int> &a) {
  if (a.size() == 0 || a.size() == 1) return 1;

  int minIndexPossible = a.size() - 1;

  for (int i = a.size() - 2; i >= 0; i--) {
    if (a[i] + i >= minIndexPossible) {
      if (i == 0) return 1;
      minIndexPossible = i;
    }
  }

  return 0;
}

int main() {
  // vector<int> a = {2, 3, 1, 1, 4};
  vector<int> a = {3, 2, 1, 0, 4};

  int isPossible = canJump(a);

  if (isPossible) cout << "Is possible." << endl;
  else cout << "Is not possible." << endl;

  return 0;
}