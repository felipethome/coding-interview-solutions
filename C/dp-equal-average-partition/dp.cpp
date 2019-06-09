/**
 * Given an array with non negative numbers, divide the array into two parts
 * such that the average of both the parts is equal. Return both parts
 * (if they exist). If there is no solution. return an empty list.
 * 
 * Example:
 * Given,
 * [1 7 15 29 11 9]
 * 
 * Output [9 15] [1 7 11 29]
 *
 * The average of part is (15+9)/2 = 12,
 * average of second part elements is (1 + 7 + 11 + 29) / 4 = 12
 * 
 * Note 1: If a solution exists, you should return a list of exactly 2 lists of
 * integers A and B which follow the following condition:
 * numElements in A <= numElements in B
 * If numElements in A = numElements in B, then A is lexicographically smaller
 * than B
 * 
 * Note 2: If multiple solutions exist, return the solution where length(A) is
 * minimum. If there is still a tie, return the one where A is lexicographically
 * smallest.
 * 
 * Note 3: Array will contain only non negative numbers.
 *
 * Time complexity: O(N^2 * S), where N is the number of elements in the array
 * and S is the maximum value the sum of the elements of this array can be. So,
 * this time complexity is pseudo-polynomial.
 * Space complexity: O(N^2 * S).
 *
 * Explanation: this exercise is tough depending on how you approach it. First,
 * you need to realize a mathematical fact, after you need to speed up the
 * algorithm and I think this is tough because if you try a bottom-up approach
 * you will not get your answer fast enough, so you need to use memoization!
 * I tried to use the dp approach for the knapsack problem and it is fast to
 * find an answer, but will not necessarily be the correct answer because this
 * exercise asks for the lexicographic smaller solution. So, once you complete
 * the knapsack table you would need to get all the possible answers to get the
 * smallest one and this process is exponential. So, to get the right answer
 * you need to sort the array and do a top-down approach because during the
 * process you naturally would find the smallest ones first.
 * The mathematical fact is:
 *
 * SUM_of_Set1 / size_of_set1 = SUM_of_Set2 / size_of_set2 
 * SUM_of_Set1 = SUM_of_Set2 * (size_of_set1 / size_of_set2)
 *
 * total_sum = Sum_of_Set1 + Sum_of_Set2
 * and size_of_set2 = total_size - size_of_set1 
 *
 * Sum_of_Set1 =
 *   (total_sum - Sum_of_Set1) * (size_of_set1 / (total_size - size_of_set1))
 * OR on simplifying, 
 *   total_sum / Sum_of_Set1 - 1 = (total_size - size_of_set1) / size_of_set1 
 *   total_sum / Sum_of_Set1 = total_size / size_of_set1 
 *   Sum_of_Set1 / size_of_set1 = total_sum / total_size 
 *
 * Now we can just iterate on size_of_set1, and we would know the required
 * Sum_of_Set1.
 *
 * To summarize, the above is saying the average of the whole list is equal
 * the average of the parts if the average of the parts are equal.
 *
 * Now that you know what you need to know (use memoization and the
 * mathematical fact) you need to implement a recursive functin to calculate
 * Sum_of_Set1. This recursive function return true if the sum exists, false
 * otherwise.
 *
 * isPossible(index, sum, size):
 *   // Include the current element
 *   isPossible(index + 1, sum - array[index], size - 1) OR
 *   // Or don't include it
 *   isPossible(index + 1, sum, size)
 *
 * Memoize the above function with a 3-dimensional vector and you are done.
 * Notice, you need in this function body to store the values that are part of
 * your group 1 (I call group 1, the group that gives Sum_of_Set1). Look at
 * the code to understand exactly how this is done, but it is simple. Just
 * push_back your values and pop_back them if you returned false.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <sys/time.h>
#include <ctime>
#include <stack>

using namespace std;

vector<vector<vector<bool> > > dp;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int index, int sum, int sz) {
  if (sz == 0) return (sum == 0);
  if (index >= total_size) return false;

  if (dp[index][sum][sz] == false) return false;

  if (sum >= original[index]) {
    res.push_back(original[index]);
    if (possible(index + 1, sum - original[index], sz - 1)) return true;
    res.pop_back();
  }
  
  if (possible(index + 1, sum, sz)) return true;

  return dp[index][sum][sz] = false;
}
  
vector<vector<int> > avgset(vector<int> &Vec) {
  sort(Vec.begin(), Vec.end());
  original.clear();
  original = Vec;
  dp.clear();
  res.clear();

  int total_sum = 0;
  total_size = Vec.size();

  for(int i = 0; i < total_size; ++i) total_sum += Vec[i];
  
  dp.resize(original.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total_size, true)));

  // We need to minimize size_of_set1. So, lets search for the first
  // size_of_set1 which is possible. 
  for (int i = 1; i < total_size; i++) {
    // Sum_of_Set1 has to be an integer
    if ((total_sum * i) % total_size != 0) continue;

    int Sum_of_Set1 = (total_sum * i) / total_size;

    if (possible(0, Sum_of_Set1, i)) {
      // Lets get the elements in group 2 now that we have group 1.
      int ptr1 = 0, ptr2 = 0;
      vector<int> res1 = res;
      vector<int> res2;
      while (ptr1 < Vec.size() || ptr2 < res.size()) {
        if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
          ptr1++;
          ptr2++;
          continue;
        }
        res2.push_back(Vec[ptr1]);
        ptr1++;
      }

      vector<vector<int> > ans;
      ans.push_back(res1);
      ans.push_back(res2);
      return ans;
    }
  }

  // Not possible.
  vector<vector<int> > ans;
  return ans;
}

int main() {
  vector<int> a;
  vector<vector<int>> tests;

  a = {1, 1};
  tests.push_back(a);
  a = {1, 2, 4, 3};
  tests.push_back(a);
  a = {1, 7, 15, 29, 11, 9};
  tests.push_back(a);
  a = {5, 16, 3, 4, 5, 2, 16, 49, 10, 35, 33, 14, 30, 40, 22, 7, 24, 38, 47, 19, 42};
  tests.push_back(a);
  a = {47, 14, 30, 19, 30, 4, 32, 32, 15, 2, 6, 24};
  tests.push_back(a);

  vector<vector<int>> r;

  for (size_t i = 0; i < tests.size(); i++) {
    r = avgset(tests[i]);

    cout << "answer:" << endl;
    for (int i = 0; i < r.size(); i++) {
      for (int j = 0; j < r[i].size(); j++) {
        cout << r[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}