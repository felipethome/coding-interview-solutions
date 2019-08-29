/**
 * There are N Mice and N holes are placed in a straight line. Each hole can
 * accomodate only 1 mouse. A mouse can stay at his position, move one step
 * right from x to x + 1, or move one step left from x to x − 1. Any of these
 * moves consumes 1 minute. Assign mice to holes so that the time when the last
 * mouse gets inside a hole is minimized.
 * 
 * Note: The final answer will fit in a 32 bit signed integer. 
 * 
 * Example:
 * positions of mice are: 4 -4 2
 * positions of holes are: 4 0 5
 * 
 * Assign mouse at position x = 4 to hole at position x = 4: Time taken is 0 
 * Assign mouse at position x = -4 to hole at position x = 0: Time taken is 4 
 * Assign mouse at position x = 2 to hole at position x = 5: Time taken is 3 
 * After 4 minutes all of the mice are in the holes.
 * 
 * Since, there is no combination possible where the last mouse's time is less
 * than 4, answer = 4.
 *
 * Time complexity: O(NlogN), where N is the size of the arrays.
 * Space complexity: O(1).
 *
 * Explanation: to solve this exercise we need to assign mice to their closest
 * holes. This way we minimize the time the mouse that is furthest to a hole
 * will take to get into one. To do that we just need to sort both of these
 * arrays so mice will be assigned to their closest holes. The maximum time
 * taken by a mouse to get into a hole is max of abs(a[i] - b[i]), where "a" is
 * mice's positions and b is the positions of the holes.
 */

#include <iostream>
#include <vector>

using namespace std;

int mice(vector<int> &a, vector<int> &b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int m = 0;

  for (int i = 0; i < a.size(); i++) {
    m = max(m, abs(a[i] - b[i]));
  }

  return m;
}

int main() {
  // vector<int> a = {4, -4, 2};
  // vector<int> b = {4, 0, 5};
  
  // vector<int> a = {-4, 4, 4, 6};
  // vector<int> b = {1, 4, 6, 8};
  
  vector<int> a = {-1, -3, 2, 6, 10, 8, 4, 1};
  vector<int> b = {-1, -2, 3, 5, 2, 8, 9, 12};

  int m = mice(a, b);

  cout << "m: " << m << endl;

  return 0;
}