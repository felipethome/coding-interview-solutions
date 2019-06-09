/**
 * Given a collection of intervals, merge all overlapping intervals.
 * Make sure the returned intervals are sorted.
 * 
 * Example:
 * 
 * Given [1,3],[2,6],[8,10],[15,18],
 * 
 * Return [1,6],[8,10],[15,18].
 *
 * Time complexity: O(NlogN), where N is the number of intervals.
 * Space complexity: O(N), where N is the number of intervals.
 *
 * Explanation: sort the intervals in ascending order by the starting point.
 * The current interval will be merged while the maximum end point found so far
 * is larger than the starting point of the current interval. When this doesn't
 * happen we insert the merged interval in the answer, create another interval
 * and start to merge again.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval i1, Interval i2) {
  return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);
}

vector<Interval> merge(vector<Interval> &a) {
  sort(a.begin(), a.end(), cmp);

  int i = 0;
  vector<Interval> ans;

  while (i < a.size()) {
    Interval *curr = new Interval(a[i].start, a[i].end);

    while (i < a.size() - 1 && curr->end >= a[i + 1].start) {
      curr->end = max(curr->end, a[i + 1].end);
      i++;
    }

    ans.push_back(*curr);
    i++;
  }

  return ans;
}

int main() {
  vector<Interval> a;

  // a.push_back(*(new Interval(1, 3)));
  // a.push_back(*(new Interval(2, 6)));
  // a.push_back(*(new Interval(8, 10)));
  // a.push_back(*(new Interval(15, 18)));
  
  a.push_back(*(new Interval(1, 10)));
  a.push_back(*(new Interval(2, 9)));
  a.push_back(*(new Interval(3, 8)));
  a.push_back(*(new Interval(4, 7)));
  a.push_back(*(new Interval(5, 6)));
  a.push_back(*(new Interval(7, 8)));

  vector<Interval> r = merge(a);

  for (Interval e : r) {
    cout << "[" << e.start << "," << e.end << "]" << " ";
  }
  cout << endl;

  return 0;
}