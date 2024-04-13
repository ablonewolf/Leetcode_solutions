#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // function to calculate largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int maxArea = 0;
        stack<int> monotonicStack;

        for (int i = 0; i <= size; i++) {
            while (!monotonicStack.empty() &&
                   (i == size || heights[monotonicStack.top()] >= heights[i])) {
                int height = heights[monotonicStack.top()];
                monotonicStack.pop();
                int width = monotonicStack.empty() ? i : i - monotonicStack.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            monotonicStack.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
          // generate the heights for each row
            for (int j = 0; j < cols; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : ++heights[j];
            }

            // calculate the area of the largest rectangle with given heights
            int area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int maxArea = solution.maximalRectangle(matrix);

    cout << "Area of the largest rectangle is: " << maxArea << endl;

}