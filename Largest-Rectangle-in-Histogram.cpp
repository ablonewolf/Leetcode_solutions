#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    return singlePassSolution(heights);
  }

  int multiPassSolution(vector<int>& heights) {
    int size = heights.size();

    stack<int> monotonicStack;
    vector<int>leftSmall(size);
    vector<int>rightSmall(size);

    // keep tracking of the left smaller entries using the monotonic stack
    for (int i = 0; i < size; i++) {
      while (!monotonicStack.empty() &&
          heights[monotonicStack.top()] >= heights[i]) {
        monotonicStack.pop();
      }

      leftSmall[i] = monotonicStack.empty() ? 0 : monotonicStack.top() + 1;
      monotonicStack.push(i);
    }

    // empty the stack to process the right smaller entries
    while (!monotonicStack.empty()) {
      monotonicStack.pop();
    }

    // process the right smaller entries using monotonic stack
    for (int i = size - 1; i >= 0; i--) {
      while (!monotonicStack.empty() &&
          heights[monotonicStack.top()] >= heights[i]) {
        monotonicStack.pop();
      }

      rightSmall[i] = monotonicStack.empty() ? size - 1 : monotonicStack.top() - 1;
      monotonicStack.push(i);
    }

    int maxArea = 0;
    int tempArea;
    for (int i = 0; i < size; i++) {
      tempArea = heights[i] * (rightSmall[i] - leftSmall[i] + 1);
      maxArea = max(maxArea, tempArea);
    }

    return maxArea;
  }

  int singlePassSolution(vector<int>& heights) {
    int size = heights.size();
    int maxArea = 0;
    stack<int> monotonicStack;

    for (int i = 0; i < size; i++) {
      while (!monotonicStack.empty() &&
          (i == size - 1 || heights[monotonicStack.top()] >= heights[i])) {
        int height = heights[monotonicStack.top()];
        monotonicStack.pop();
        int width = monotonicStack.empty() ? i : i - monotonicStack.top() - 1;
        maxArea = max(maxArea, width * height);
      }
      monotonicStack.push(i);
    }

    return maxArea;
  }
};

int main() {
  Solution so;
  vector<int> heights = { 2, 3, 1, 5, 6, 2, 4 };
  int area = so.largestRectangleArea(heights);
  cout << "Max rectangular histogram area: " << area << endl;
}