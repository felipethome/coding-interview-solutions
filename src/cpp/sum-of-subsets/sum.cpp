/*
 * Given an array of numbers make an array containing all the possible sums
 * of the elements of this array.
 *
 * Time complexity: O((2^N) * N), where N is the size of the array.
 */

#include <iostream>
#include <vector>

void sum_of_all_subset(std::vector<int> s) {
  int n = s.size();
  int results[(1 << n)]; // (1 << n) = 2^n

  // initialize results to 0
  memset(results, 0, sizeof(results));

  // iterate through all subsets
  for (int i = 0 ; i < (1 << n); ++i) { // for each subset, O(2^n)
    for (int j = 0; j < n; ++j) { // check membership, O(n)
      if ((i & (1 << j)) != 0) // test if bit ‘j’ is turned on in subset ‘i’?
        results[i] += s[j]; // if yes, process ‘j’
    }
  }
}

int main() {
  std::cout << "Hello World!";

  return 0;
}