/**
 * Given an array of integers, sort the array into a wave like array and return
 * it, in other words, arrange the elements into a sequence such that
 * a1 >= a2 <= a3 >= a4 <= a5.....
 * Note: If there are multiple answers possible, return the one of the one
 * thats lexicographically smallest. So, in example case, you will return
 * [2, 1, 4, 3].
 * 
 * Example:
 * 
 * Given [1, 2, 3, 4]
 * One possible answer: [2, 1, 4, 3]
 * Another possible answer: [4, 1, 3, 2]
 *
 * Time complexity: O(NlogN), where N is the size of the array. A O(N) solution
 * is possible using the median, though it is not guaranteed to be the
 * lexicographically smallest.
 * Space complexity: O(1).
 *
 * Explanation: just sort the array and switch each two neighbors.
 *
 * Not lexicographically smallest solutions:
 * Call the median M, half of the array will be smaller or equal to M, and the
 * other half will be larger than M. If we call the smaller elements L (for
 * left) and R (for right) the larger ones we can see an array as something
 * like:
 * a = [L, R, R, R, R, L, L, L]
 * One way to rearrange the elements to obey the wave rule is:
 * a = [R, L, R, L, R, L, R, L]
 * So, using the median we can check if the current element E1 is in a position
 * it could be (R needs to be in even indices and L in odd indices) and if it
 * is not we just look for the next element that would fit in that place E2.
 * Then, we swap E1 and E2. Notice, we don't need to go back to the position
 * where E1 was. We just update our first pointer to position E1 + 2 (plus 2
 * because the next element to E1 after the swap will definitely be in its
 * correct position) and we continue to look for suitable elements from the
 * position of E2.
 *
 * A better solution there is O(N), but much simpler.
 * All we need to guarantee is that even positioned elements are bigger than
 * odd positioned elements. So, we iterate through the even positioned elements
 * and we do:
 * 1. If current element is smaller than previous odd element, swap previous
 * and current.
 * 2. If current element is smaller than next odd element, swap next and
 * current.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> wave(vector<int> &a) {
  int n = a.size();

  // Traverse all even elements
  for (int i = 0; i < n; i += 2) {
    // If current even element is smaller than previous
    if (i > 0 && a[i - 1] > a[i]) swap(a[i], a[i - 1]);

    // If current even element is smaller than next
    if (i < n - 1 && a[i] < a[i + 1]) swap(a[i], a[i + 1]);
  }

  return a;
}

// vector<int> wave(vector<int> &a) {
//   int n = a.size(), m = median(a), i = 0, j = 0;

//   while (i < n && j < n) {
//     bool l = i % 2 ? true : false;

//     if (i == j && ((l && a[i] <= m) || (!l && a[i] > m))) {
//       i++;
//       j++;
//     }
//     else {
//       if (l) while (i < n && a[i] > m) i++;
//       else while (i < n && a[i] <= m) i++;

//       if (i < n) {
//         swap(a[i], a[j]);
//         i++;
//         j += 2;
//       }
//     }
//   }

//   return a;
// }

// Lexicographically smallest solution. Sort the away and swap neighbors.
// vector<int> wave(vector<int> &a) {
//   sort(a.begin(), a.end());

//   for (int i = 0; i < a.size() - 1; i += 2) {
//     swap(a[i], a[i + 1]);
//   }

//   return a;
// }

int main() {
  vector<int> a = {5, 4, 3, 2, 1};

  vector<int> r = wave(a);

  for (int e : r) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}