#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int ans = rows * (1 << (cols - 1 - 0));

        for (int col = 1; col < cols; col++) {
            int oneCount = 0;

            for (int row = 0; row < rows; row++) {
                oneCount += grid[row][0] == 0 ? grid[row][col] ^ 1 : grid[row][col];
            }

            if (oneCount < rows - oneCount) {
                ans += (rows - oneCount) * (1 << (cols - 1 - col));
            } else {
                ans += (oneCount) * (1 << (cols - 1 - col));
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = { {0, 0, 1, 1},{1, 0, 1, 0},{1, 1, 0, 0} };
    Solution solution;
    int matrixScore = solution.matrixScore(grid);
    cout << "Matrix score is: " << matrixScore << "." << endl;
}