#include <vector>
#include <climits>
#include <cstring>
using namespace std;
class Solution {
public:
    int possibleWays[3] = { 0, -1, 1 };
    int memArray[71][71][71];

    int dfs(vector<vector<int>>& grid, int i, int column1, int column2, int rows, int cols) {
        if (i == rows)
            return 0;
        if (column1 < 0 || column2 < 0 ||
         column1 >= cols || column2 >= cols)
            return INT_MIN;
        if (memArray[i][column1][column2] != -1)
            return memArray[i][column1][column2];

        int result = 0;
        for (int k = 0; k < 3; k++) {
            for (int r = 0; r < 3; r++) {
                result = max(result, dfs(grid, i + 1, column1 + possibleWays[k], column2 + possibleWays[r], rows, cols));
            }
        }

        result += (column1 == column2) ? grid[i][column1] : grid[i][column1] + grid[i][column2];
        return memArray[i][column1][column2] = result;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(); // rows
        if (!rows)
            return 0;
        int cols = grid[0].size(); // cols
        memset(memArray, -1, sizeof memArray);
        return dfs(grid, 0, 0, cols - 1, rows, cols);
    }
};