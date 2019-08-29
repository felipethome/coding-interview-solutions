/**
 * Find out the maximum sub-array of non negative numbers from an array.
 * The sub-array should be continuous. That is, a sub-array created by choosing
 * the second and fourth element and skipping the third element is invalid.
 * 
 * Maximum sub-array is defined in terms of the sum of the elements in the
 * sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).
 * 
 * Example:
 * A : [1, 2, 5, -7, 2, 3]
 * The two sub-arrays are [1, 2, 5] [2, 3].
 * The answer is [1, 2, 5] as its sum is larger than [2, 3]
 *
 * Note 1: If there is a tie, then compare with segment's length and return
 * segment which has maximum length.
 * Note 2: If there is still a tie, then return the segment with minimum
 * starting index.
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 *
 * Explanation: just iterate over the array. While you are looking at positive
 * elements store the elements in another array. Also keep a sum of these
 * elements you are storing. When you find a negative element stop storing and
 * see if the sum you have now is bigger than the previous sum, if it is store
 * this array you just made in your answer. When you find another positive
 * number start the process again. Keep doing this while you still have
 * elements to look at in the array.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> maxset(vector<int> &a) {
  vector<int> ans;
  int i = 0;
  long long sum = 0;

  while(i < a.size()) {
    vector<int> temp;
    int j = i;
    long long currSum = 0;

    while (j < a.size() && a[j] >= 0) {
      currSum += a[j];
      temp.push_back(a[j]);
      j++;
    }

    if (currSum > sum) {
      ans = temp;
      sum = currSum;
    }
    else if (currSum == sum) {
      if (temp.size() > ans.size()) ans = temp;
    }

    i = j + 1;
  }

  return ans;
}

int main() {
  // vector<int> a = {3, 2, 1, -3, 0, -2, 6, 0, 1};
  vector<int> a = {1967513926, 1540383426, -1303455736, -521595368};

  vector<int> r = maxset(a);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}