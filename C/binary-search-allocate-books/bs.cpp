/**
 * N number of books are given. The ith book has Pi number of pages. You have
 * to allocate books to M number of students so that maximum number of pages
 * alloted to a student is minimum. All books need to be allocated. A book will
 * be allocated to exactly one student. Each student has to be allocated at
 * least one book. Allotment should be in contiguous order, for example: A
 * student cannot be allocated book 1 and book 3, skipping book 2.
 * 
 * Notes:
 * 1. Return -1 if a valid assignment is not possible
 * 2. Your function should return an integer corresponding to the minimum
 * number.
 *
 * Example:
 * 
 * P = [12, 34, 67, 90]
 * M = 2
 * 
 * Output 113
 * 
 * There are 2 number of students. Books can be distributed in following
 * fashion: 
 * 1. [12] and [34, 67, 90]
 * Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
 * 2. [12, 34] and [67, 90]
 * Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
 * 3. [12, 34, 67] and [90]
 * Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
 * 
 * Of the 3 cases, Option 3 has the minimum pages = 113.
 *
 * Time complexity: O(logB * N), where B is the number of bits for the variable
 * used to hold the sum of the pages and N is the number of elements in the
 * given array.
 * Space complexity: O(1).
 *
 * Explanation: the way this exercise is formulated it is difficult to see what
 * it is really asking. You are not supposed to distribute the books, but to
 * find out what is the minimum sum for the array partition with the maximum
 * sum. So, in other words, we want to find:
 * Given a number P of pages is it possible with the number of students that
 * was given for every student to read at most P pages, and if it is can we make
 * P smaller?
 * So, if we have the total number of pages T (a1 + a2 + ... + ai). We can look
 * for P using binary search:
 *
 *      mid = (0 + T) / 2
 * 0 .........................T
 *
 * Now, if we are able to calculate how many student we need to read mid pages,
 * and we find out that is a number less or equal to the given number of
 * students M, then of course any number larger than mid will require the same
 * number of students or even less. So we can discard every number larger than
 * M because we are interested in the minimum number of pages. When we find
 * the smallest possible mid, then we found our answer.
 *
 * How to find out if the given number of students is enough to read mid pages?
 * Since the distribution needs to be contiguous we just sum the pages in the
 * array until it gets larger than mid. At this point we need to increment the
 * number of students because a student can read at most mid pages, so if it
 * is more than that we need one more student. Now, we start our sum again and
 * perform the same thing. In the end, if the number we got is less than or
 * equal to the given number it is possible that with at most mid pages the
 * students can read everything so we try to make mid smaller.
 */

#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &a, int b, int mid) {
  int sum = 0, count = 1;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] > mid) return false;

    if (sum + a[i] > mid) {
      count++;
      sum = a[i];
      if (count > b) return false;
    }
    else {
      sum += a[i];
    }
  }

  return true;
}

int books(vector<int> &a, int b) {
  if(a.size() < b) return -1;

  int ans = INT_MAX;
  long long low = 0, high = 0, mid;

  for (int i = 0; i < a.size(); i++) high += a[i];

  while (low <= high) {
    mid = (high + low) / 2;

    if (isPossible(a, b, mid)) {
      ans = min(ans, (int)mid);
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return ans;
}

int main() {
  vector<int> a = {12, 34, 67, 90};
  int b = 2;

  int r = books(a, b);

  cout << r << endl;

  return 0;
}