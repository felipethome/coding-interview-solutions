/**
 * Given an array of N integers, find the pair of integers in the array which
 * have minimum XOR value. Report the minimum XOR value.
 *
 * Constraints: 
 * 2 <= N <= 100 000 
 * 0 <= A[i] <= 1 000 000 000
 * 
 * Examples:
 * Input
 * 0 2 5 7 
 * Output 
 * 2 (0 XOR 2)
 *
 * Input
 * 0 4 7 9
 * Output
 * 3 (4 XOR 7)
 *
 * Time complexity: O(NlogN) or O(N) depending on implementation, where N is
 * the size of the given array.
 * Space complexity: O(1) or O(N) depending on implementation.
 *
 * Explanation: there are two nice solutions for this problem.
 *
 * First approach:
 * Sort the elements, iterate over the array performing XOR for each consecutive
 * pair and keep the smallest. Sorting makes the elements with most similar bits
 * stay side by side and it makes sense since XOR is binary sum without carry.
 *
 * Second approach:
 * Use a trie. This solution uses more memory, but has linear time complexity.
 * Our alphabet for this trie is 0 and 1 only. If we insert in the trie the bits
 * starting from the MSB (Most Significant Bit) the most similar element B that
 * we can find in this trie for another element A is the smallest XOR that we
 * could find for A. So we iterate over the array looking in the trie for the
 * most similar element to the current element. Every time we get a mismatch
 * (the bit we are current looking is not present in the trie for the prefix
 * we are) we just check the other bit. Notice we just insert the current
 * element after we looked in the trie for its most similar element, because,
 * of course, if the current element was already in the trie then it would be
 * the most similar element to itself.
 */

#include <iostream>
#include <vector>

using namespace std;

#define INT_SIZE 32

int findMinXor(vector<int> &a) {
  int ans = INT_MAX;
  sort(a.begin(), a.end());
  
  for (int i = 0; i < a.size() - 1; i++) {
      ans = min(ans, a[i] ^ a[i + 1]);
  }

  return ans;
}

// Solution using Trie. Time complexity: O(N), space complexity: O(N).
// struct TrieNode {
//   int val;
//   vector<TrieNode*> keys;
//   TrieNode() : val(0), keys(2, NULL) {}
// };

// void insert(TrieNode *root, int val) {
//   TrieNode *curr = root;

//   for (int i = (INT_SIZE - 1); i >= 0; i--) {
//     bool currBit = val & (1 << i);
//     if (curr->keys[currBit] == NULL) {
//       curr->keys[currBit] = new TrieNode();
//     }
//     curr = curr->keys[currBit];
//   }

//   curr->val = val;
// }

// int findMinXorUtil(TrieNode *root, int val) {
//   TrieNode *curr = root;

//   for (int i = (INT_SIZE - 1); i >= 0; i--) {
//     bool currBit = val & (1 << i);
//     if (curr->keys[currBit] != NULL) {
//       curr = curr->keys[currBit];
//     }
//     else if (curr->keys[!currBit] != NULL) {
//       curr = curr->keys[!currBit];
//     }
//   }

//   return val ^ curr->val;
// }

// int findMinXor(vector<int> &a) {
//   int ans = INT_MAX;
//   TrieNode *root = new TrieNode();

//   insert(root, a[0]);

//   for (int i = 1; i < a.size(); i++) {
//     ans = min(ans, findMinXorUtil(root, a[i]));
//     insert(root, a[i]);
//   }

//   return ans;
// }

int main() {
  // vector<int> a = {0, 2, 5, 7};
  // vector<int> a = {12, 4, 6, 2};

  int r = findMinXor(a);

  cout << r << endl;

  return 0;
}