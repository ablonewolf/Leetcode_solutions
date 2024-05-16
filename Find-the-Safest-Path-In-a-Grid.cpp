#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows = grid.size();
        queue<vector<int>> distances;

        // pushing the thief cells into the distances queue and marking their distance as 0.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < rows; col++) {
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    distances.push({ row, col, 0 });
                } else {
                    grid[row][col] = -1;
                }
            }
        }

        int directions[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

        // calculating the distances from empty cells to the nearest thiefs
        while (!distances.empty()) {
            auto current = distances.front();
            distances.pop();

            int x = current[0], y = current[1], distance = current[2];

            for (int i = 0; i < 4; i++) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];

                if (newX < 0 || newY < 0 || newX >= rows || newY >= rows || grid[newX][newY] != -1) {
                    continue;
                } else {
                    grid[newX][newY] = 1 + distance;
                    distances.push({ newX, newY, grid[newX][newY] });
                }
            }

        }

        // checking whether the cells are visited or not and traversing through the minimum path.
        // we are using the maxHeap to go the next cell which is at the most distance from the thief.
        // and, in that path, we will use the closest cell on that generated path and its distance.
        priority_queue<vector<int>> maxHeap;

        // we are initially assuming that max safeness factor will be found in the {0, 0}th cell
        maxHeap.push({ grid[0][0], 0, 0 });
        grid[0][0] = -1;

        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();

            int distance = current[0], x = current[1], y = current[2];

            // if we are at the destination, that means the distance between it and the thief is the safeness factor
            if (x == rows - 1 && y == rows - 1) {
                return distance;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];

                if (newX < 0 || newY < 0 || newX >= rows || newY >= rows || grid[newX][newY] == -1) {
                    continue;
                }

                // storing the minimum manhattan distance from the current cell to the thief cell.
                int minDistance = min(distance, grid[newX][newY]);
                maxHeap.push({ minDistance, newX, newY });
                grid[newX][newY] = -1; // marking the cell visisted.

            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0}
    };

    Solution solution;
    cout << solution.maximumSafenessFactor(grid) << endl;
}