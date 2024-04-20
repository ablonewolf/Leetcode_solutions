#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int DFS(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 1;
        }

        if (grid[row][col] == -1) {
            return 0;
        }

        grid[row][col] = -1;

        return (DFS(grid, row + 1, col) +
                DFS(grid, row - 1, col) +
                DFS(grid, row, col + 1) +
                DFS(grid, row, col - 1));
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    perimeter += DFS(grid, row, col);
                }
            }
        }

        return perimeter;
    }

};

int main() {

}