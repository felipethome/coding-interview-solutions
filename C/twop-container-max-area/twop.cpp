/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). 'n' vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water. In other words, given an array of non-negative integers, where each
 * element represents a point (i, a[i]) find the square with the largest area
 * represented by the lines drawn with this points and x axis.
 * 
 * Your program should return an integer which corresponds to the maximum area
 * of water that can be contained ( Yes, we know maximum area instead of maximum
 * volume sounds weird. But this is 2D plane we are working with for
 * simplicity).
 * 
 * Notes:
 * 1. You may not slant the container.
 * 
 * Example:
 * 
 * Input [1, 5, 4, 3]
 * Output 6, because 5 and 3 are distance 2 apart. So size of the base = 2.
 * Height of container = min(5, 3) = 3. So total area = 3 * 2 = 6
 *
 * Time complexity: O(N), where N is the size of the given array.
 * Space complexity: O(1).
 *
 * Explanation: You start with a pointer at the begining of the array and one
 * at the end. Since the beginning and end represent the longest base you could
 * have, for the next area to be larger needs to have a height longest than the
 * previous one (and height = min(a[start], a[end])). So, you have:
 * 1. If a1 < aN, then the problem reduces to solving the same thing for a2, aN. 
 * 2. Else, it reduces to solving the same thing for a1, aN-1
 */

#include <iostream>
#include <vector>

using namespace std;

int calcArea(vector<int> &a, int i, int j) {
  return (j - i) * min(a[i], a[j]);
}

int maxArea(vector<int> &a) {
  int area = 0, i = 0, j = a.size() - 1;
  
  while (i < j) {
    area = max(area, calcArea(a, i, j));

    if (a[i] < a[j]) {
      i++;
    }
    else {
      j--;
    }
  }
  
  return area;
}

int main() {
  vector<int> v = { 726, 6271, 2235, 9392, 4114, 1244, 6687, 9727, 9026, 7181, 9225, 6199, 8514, 3526, 5070, 4683, 100, 9693, 2878, 8792, 4454, 3121, 7856, 3293, 180, 3424, 1085, 3893, 3025, 310, 7866, 6064, 9015, 8994, 4753, 5196, 7089, 1738, 5803, 664, 8824, 3378, 7333, 4820, 2417, 4691, 7321, 1488, 4747, 3663, 7896, 2392, 6431, 1810, 866, 5738, 7384, 6896, 9007, 4772, 7728, 9739, 4380, 2309, 8904, 3825, 6604, 9577, 2983, 2286, 4703, 1603, 8405, 3889, 2922, 9445, 4585, 9403, 3056, 1979, 7389, 5175, 9927, 4510, 369, 4895, 8531, 9424, 5494, 8338, 738, 5615, 4707, 1682, 6418, 7274, 1522, 9687, 3725, 7274, 3280, 153, 6692, 3231, 3176, 2115, 7411, 7536, 6307, 370, 9519, 156, 2481, 9442, 7683, 2335, 1170, 4462, 6801, 6079, 9305, 9585, 1934, 4579, 4051, 1650, 3608, 4756, 5816, 4235, 5280, 2953, 1804, 8554, 7815, 7996, 1817, 3877, 9575, 2365, 5043, 6609, 6774, 2735, 6719, 9434, 1026, 5280, 8356, 5523, 2844, 4229, 8004, 7364, 8753, 8929, 8919, 1490, 2885, 5906, 6945, 6729, 3916, 5443, 4040, 5042, 6827, 5298, 9726, 4234, 1028, 245, 7931, 3360, 4935, 7309, 4965, 933, 4144, 5603, 6509, 6010, 3219, 5639, 5582, 9437, 129, 7377, 1661, 3954, 2970, 9649, 966, 9489, 5575, 1297, 5177, 4929, 643, 6018, 8920, 974, 352, 1945, 3276, 4652, 5517, 6903, 7144, 1281, 9605, 1139, 4453, 5201, 7189, 1490, 7016, 3980, 5086, 4212, 5109, 950, 4788, 1319, 6724, 8810, 472, 8078, 943, 8469, 8332, 2470 };
  int area = maxArea(v);

  cout << '\n' << "Area: " << area << '\n';

  return 0;
}