/**
 * N light bulbs are connected by a wire. Each bulb has a switch associated with
 * it, however due to faulty wiring, a switch also changes the state of all the
 * bulbs to the right of current bulb. Given an initial state of all bulbs, find
 * the minimum number of switches you have to press to turn on all the bulbs.
 * You can press the same switch multiple times.
 * 
 * Note : 0 represents the bulb is off and 1 represents the bulb is on.
 *
 * Example:
 * Given [0 1 0 1], return 4
 *   press switch 0 : [1 0 1 0]
 *   press switch 1 : [1 1 0 1]
 *   press switch 2 : [1 1 1 0]
 *   press switch 3 : [1 1 1 1]
 *
 * Time complexity: O(N), where N is the size of the array.
 * Space complexity: O(1).
 *
 * Explanation: since just the bulbs at the right of the current bulb have
 * their state changed, there is no way to change the first 0 bulb to 1 unless
 * we perform that change when we are at it. So, just do that. Iterate from the
 * beginning of the array and at each time you find a "off" bulb turn it on
 * and look for the next "off" bulb.
 */

#include <iostream>
#include <vector>

using namespace std;

int bulbs(vector<int> &a) {
  bool invert = false;
  int m = 0;
  
  for (int i = 0; i < a.size(); i++) {
    if (invert == false) {
      if (a[i] == 0) {
        m++;
        invert = true;
      }
    }
    else {
      if (a[i] == 1) {
        m++;
        invert = false;
      }
    }
  }
  
  return m;
}

int main() {
  vector<int> a = {0, 1, 0, 1};

  int m = bulbs(a);

  cout << "m: " << m << endl;

  return 0;
}