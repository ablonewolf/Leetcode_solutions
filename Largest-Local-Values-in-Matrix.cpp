#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int rows = grid.size();

        vector<vector<int>> result(rows - 2, vector<int>(rows - 2));

        for (int row = 1; row < rows - 1; row++) {
            for (int col = 1; col < rows - 1; col++) {
                int temp = 0;

                for (int i = row - 1; i <= row + 1; i++) {
                    for (int j = col - 1; j <= col + 1; j++) {
                        temp = max(temp, grid[i][j]);
                    }
                }

                result[row - 1][col - 1] = temp;
            }
        }

        return result;
    }
};