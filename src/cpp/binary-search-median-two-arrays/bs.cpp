/**
 * There are two sorted arrays A and B of size M and N respectively. Find the
 * median of the two sorted arrays (The median of the array formed by merging
 * both the arrays).
 * 
 * The overall run time complexity should be O(log(M + N)).
 * 
 * Notes:
 * 1. If the number of elements in the merged array is even, then the median
 * is the average of N / 2 th and N / 2 + 1th element. For example, if the array
 * is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 
 * 
 * Example:
 * 
 * A = [1 4 5]
 * B = [2 3]
 * 
 * Output = 3
 *
 * Time complexity: O(log(M + N)), where M is the size of one array and N is the
 * size of the other array.
 * Space complexity: O(1), in iterative implementation, O(log(M + N)) using
 * recursion.
 *
 * Explanation:
 * We want to find the Kth smallest element. For that, we basically want to
 * find a position i in the first array, and a position j in the second array,
 * so that i + j = k - 1. Since at position i we have i elements smaller than
 * A[i], and at position j we have j elements smaller than B[j]. We need to
 * maintain this property in our iterations.
 *
 * To solve this problem we can look at the likely Kth smallest elements, which
 * will be at position (A_start|B_start) + i, where i = k / 2, because k / 2
 * elements from the first array plus k / 2 elements of the second array
 * we respect the property i + j = k - 1.
 * 
 * In practice we can only guaratee that
 * for k, we have k / 2 elements behind min(A[A_start + i], B[B_start + i]), so
 * we find k / 2 smallest elements at each iteration:
 *
 * 1. A[A_start + i] < B[B_start + i], then we can discard all elements in A
 * with indices smaller than i, because A[A_start + i] could be at most the
 * (k - 1)th smallest element. And we can discard all elements in B at positions
 * larger than i, since B[B_start + i] will be the kth smallest element or the
 * (k + x)th smallest element for some x > 0.
 * 2. B[B_start + i] < A[A_start + i], same as above, but change A with B.
 *
 * So, we are trying to find the Kth smallest element for each k / 2 partition,
 * where k / 2 is updated recursively, like (((k / 2) / 2) / 2) and so on. This
 * show us that our time complexity will be O(log(k)) and k can be at most
 * M + N, so we get O(log(M + N)).
 *
 * For example, given,
 * A = [-50, -21, -10]
 * B = [-50, -41, -40, -19, 5, 21, 28]
 *
 * We define findKth(A, As, B, Bs, k),
 * Where A and B are the input arrays, As and Bs are integers that indicate
 * where we jound start our search in A and B respectively, and k indicates
 * which kth smallest element we are searching.
 * 
 * We get,
 * M = 3, N = 7
 * 
 * M + N is even so we need to look for two k's,
 * k = (M + N) / 2 = 5, k = (M + N) / 2 + 1 = 6
 *
 * Lets take a look at case k = 6
 *
 * #1
 * As = 0, Bs = 0, k = 6
 * i = k / 2 - 1 = 2 (the -1 comes from the fact that we use 0 based indices)
 * A[As + i] = -10, B[Bs + i] = -40
 * B[Bs + i] < A[As + i], so we discard in B, every element up to B[i], and
 * every element larger than A[As + i], doing k - k / 2 we guarantee that we
 * will not go further A[As + i], and doing Bs + k / 2 we start our searching
 * for B in the next iteration beyond B[Bs + i]. Notice that k - k / 2 is not
 * necessary equal k / 2, it can be also k / 2 + 1, which will be the correct
 * value for odd k.
 *
 * #2
 * As = 0, Bs = 3, k = 3
 * i = k / 2 - 1 = 0
 * A[As + i] = -50, B[Bs + i] = -19
 * A[As + i] < B[Bs + i], so we discard elements up to A[As + i], and elements
 * after B[Bs + i].
 *
 * #3
 * As = 1, Bs = 3, k = 2
 * i = k / 2 - 1 = 0
 * A[As + i] = -21, B[Bs + i] = -19
 * A[As + i] < B[Bs + i], so we discard elements up to A[As + i], and elements
 * after B[Bs + i].
 *
 * #4
 * As = 2, Bs = 3, k = 1
 * k = 1, so we return min(A[As], B[Bs]), which is -19
 *
 * Editorial Solution
 * This problem will use binary search to find the median and avoid
 * merging the array which would be a linear operation.
 *
 * If we can divide both arrays, one at point i and the other at point j, in
 * a way that all the elements in the left part (left part of first array plus
 * left part of the second array) are smaller than all the elements in the
 * right part (right part of first array plus right part of the second array),
 * so we can find the median as one of the middle left extremes of these parts:
 *
 * Left           Right
 * [x1 x2 x3]    [x4 x5]
 * [y1 y2]       [y3 y4]
 *
 * If all elements in left are smaller than all elements in right, then the
 * median needs to be one of x3, y2. That is obvious if you think that this is
 * exactly what a median does: divies the array into two equal parts, left and
 * right, where all elements in the left part are smaller than all elements in
 * the right part (notice the left part can have one more element than the
 * right part).
 *
 * The trick is that we can find i with binary search. Once, we have i, j is
 * just a calculation because for each i we need to guarantee j divides the
 * second array in a way that left(i) + left(j) = right(i) + right(j), where
 * left(i or j) and right(i or j) are the number of elements in the left/right
 * part for a division happening at point i/j. Remembering that actually the
 * left part can have one more element than the right part if the total number
 * of elements is odd, we add 1 to the right part to make things equal (and
 * add 1 in the "even" case will "floor" to the correct value if we didn't have
 * added 1, because 1 / 2 will give 0.5):
 *
 * Right 1       Right 2             Left 1          Left 2
 * (M - i)   +   (N - j)   +   1   =   i       +       j
 * 
 * Which simplifies to j = ((M + N + 1) / 2) - i
 * 
 * Now, the question that emerges is: why we can use binary search?
 * Since the arrays are sorted to check if we have our condition that all
 * elements in the left part are smaller than all the elements in the right part
 * we just need to check the elements in the division indices i and j as:
 * 
 * x4 > y2 and y3 > x3
 *
 * If this condition is true so all the following elements after y3 and x4
 * will be larger than x3 and y2 since the arrays are sorted. Now, if the
 * condition is false it means that for that particular i and j, or x4 is
 * is smaller than y2 or y3 is smaller than x3, and we can get:
 *
 * 1. x4 < y2, means we can discard all indices smaller than i, because if x4
 * is smaller than y2, so will be x3, x2, x1.
 * 2. y3 < x3, means we can discard all indices larger than i, because if y3
 * is smaller than x3 , so it will be smaller than x4 and x5 too.
 *
 * We just defined our binary search, but there are a couple of things that I
 * will highlight because they will matter for the implementation:
 *
 * 1. Be sure N is larger than M, because in the equation
 * j = ((m + n + 1) / 2) - i, (m + n + 1) needs to be larger than i, otherwise
 * when you subtract i you could get a negative j.
 * 2. i = 0 means the left part of the first array is empty, beacause i means
 * the amount of elements in the left part. So, m - i, is the amount of elements
 * in the right part. Same thing goes for j.
 * 3. The median when M + N is even will always be: max(A[i - 1], B[j - 1]).
 * 4. The median when M + N is odd will always be:
 * max(A[i - 1], B[j - 1]) + min(A[i], B[j])).
 */

#include <iostream>
#include <vector>

using namespace std;

// This function can also be iterative.
int findKth(const vector<int> &A, int A_start, const vector<int> &B, int B_start, int k) {
  // If we don't have any more elements to look at A, find kth directly in B.
  if (A_start >= A.size()) return B[B_start + k - 1];
  // If we don't have any more elements to look at B, find kth directly in A.
  if (B_start >= B.size()) return A[A_start + k - 1];

  // Our base case.
  if (k == 1) return min(A[A_start], B[B_start]);
  
  // Our indices is 0 based, but our kth element is 1 based, so we subtract 1.
  int A_key = A_start + k / 2 - 1 < A.size() ? A[A_start + k / 2 - 1] : INT_MAX;
  int B_key = B_start + k / 2 - 1 < B.size() ? B[B_start + k / 2 - 1] : INT_MAX;
  
  if (A_key < B_key) {
    // If A_key < B_key we can discard all elements from 0 to A_key in A and 
    // we can discard all elements larger than B_key in B.
    // Notice that k - k / 2 is not necessarily equal to k / 2, it can also be
    // k / 2 + 1 which is the right choice for odd k.
    return findKth(A, A_start + k / 2, B, B_start, k - k / 2);
  }
  else {
    // Same thing as above but we switch A with B.
    return findKth(A, A_start, B, B_start + k / 2, k - k / 2);
  }
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
  int len = A.size() + B.size();

  if (len % 2 == 1) {
    return findKth(A, 0, B, 0, len / 2 + 1);
  }
  else {
    return 0.5 * (findKth(A, 0, B, 0, len / 2) +
      findKth(A, 0, B, 0, len / 2 + 1));
  }
}

// double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
//   int m = A.size(), n = B.size();

//   // Be sure array B is larger than array A. In the equation
//   // j = (m + n + 1) / 2 - i, (m + n + 1) needs to be larger than i, otherwise
//   // when you subtract i you could get a negative j.
//   if (m > n) return findMedianSortedArrays(B, A);

//   int low = 0, high = m; 

//   while (low <= high) {
//     int i = (low + high) / 2, j = (m + n + 1) / 2 - i;

//     if (j > 0 && i < m && B[j - 1] > A[i]) low = i + 1;
//     else if (i > 0 && j < n && A[i - 1] > B[j]) high = i - 1;
//     else {
//       // We met our condition that all elements elements in the left part needs
//       // to be smaller than all the elements in the right part, so lets find
//       // the median.
//       int median1 = 0, median2 = 0;

//       if (i == 0) median1 = B[j - 1];
//       else if (j == 0) median1 = A[i - 1];
//       else median1 = max(A[i - 1], B[j - 1]);

//       // If the number of elements in the array is odd our median is the middle
//       // element.
//       if ((m + n) % 2 == 1) return 1.0 * median1;

//       // If the number of elements in the array is even our median is the
//       // average of median1 and the element next to it.
//       if (i == m) median2 = B[j];
//       else if (j == n) median2 = A[i];
//       else median2 = min(A[i], B[j]);

//       return 1.0 * (median1 + median2) / 2.0;
//     }
//   }

//   // If the median does not exist (empty arrays).
//   return -1.0;
// }

int main() {
  vector<int> a = {2, 3, 6, 8, 9, 12};
  vector<int> b = {1, 4, 5, 7, 10, 13, 17};

  // vector<int> a = {1, 1, 2, 3, 10, 13};
  // vector<int> b = {-1, 2, 3, 4, 6, 7};

  // vector<int> a = {-1, 1, 1, 2, 2, 3, 3, 4, 6, 7, 10, 13};
  // vector<int> b = {};

  // vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 17};
  // vector<int> b = {};

  int r = findMedianSortedArrays(a, b);

  cout << r << endl;

  return 0;
}