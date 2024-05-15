#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMaxGold(int row, int col, int rowSize, int colSize, vector<vector<int>>& grid) {
        if (row < 0 || row >= rowSize || col < 0 || col >= colSize || grid[row][col] == 0) {
            return 0;
        }

        int currentGold = grid[row][col];
        grid[row][col] = 0; // Mark the cell as visited by setting it to 0

        // Recursively explore all four directions
        int down = findMaxGold(row + 1, col, rowSize, colSize, grid);
        int up = findMaxGold(row - 1, col, rowSize, colSize, grid);
        int right = findMaxGold(row, col + 1, rowSize, colSize, grid);
        int left = findMaxGold(row, col - 1, rowSize, colSize, grid);

        // Restore the cell value
        grid[row][col] = currentGold;

        return currentGold + max({ down, up, right, left });
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rowSize = grid.size(), colSize = grid[0].size();
        if (rowSize == 0) {
            return 0;
        }
        int maxGold = 0;

        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                if (grid[row][col] == 0) {
                    continue;
                } else {
                    maxGold = max(findMaxGold(row, col, rowSize, colSize, grid), maxGold);
                }
            }
        }

        return maxGold;
    }
};

int main() {

}