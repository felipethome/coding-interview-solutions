#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> &a) {
  stack<int> posStack;
  int height, width, area, maxArea = 0;

  for (int i = 0; i < a.size();) {
    if (posStack.empty() || a[posStack.top()] <= a[i]) {
      posStack.push(i++);
    }
    else {
      while (!posStack.empty() && a[posStack.top()] > a[i]) {
        height = a[posStack.top()];
        posStack.pop();
        width = !posStack.empty() ? i - (posStack.top() + 1) : i;
        area = width * height;
        maxArea = max(maxArea, area);
      }
    }
  }

  while (!posStack.empty()) {
    height = a[posStack.top()];
    posStack.pop();
    width = !posStack.empty() ? a.size() - (posStack.top() + 1) : a.size();
    area = width * height;
    maxArea = max(maxArea, area);
  }

  return maxArea;
}

int main() {
  // vector<int> a = {1, 2, 4}; // 4
  // vector<int> a = {2, 1, 2, 3, 1}; // 5
  // vector<int> a = {2, 1, 5, 6, 2, 3}; // 10
  // vector<int> a = {90, 58, 69, 70, 82, 100, 13, 57, 47, 18}; // 348
  vector<int> a = {6, 2, 5, 4, 5, 1, 6}; // 12

  int maxArea = largestRectangleArea(a);

  cout << "Max area: " << maxArea << endl;

  return 0;
}