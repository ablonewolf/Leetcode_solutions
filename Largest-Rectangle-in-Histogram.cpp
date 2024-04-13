#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
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
};