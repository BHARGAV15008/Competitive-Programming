/*
1594. Maximum Non Negative Product in a Matrix

You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
Notice that the modulo is performed after getting the maximum product.

Example 1:

Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
Example 2:

Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
Example 3:

Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
-4 <= grid[i][j] <= 4
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>


class MaxProductPath {
public:
    int maxProductPath(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        std::vector<std::vector<std::pair<long long, long long>>> memoTable(m, std::vector<std::pair<long long, long long>>(n));
        memoTable[0][0] = {grid[0][0], grid[0][0]};

        for (int j = 1; j < n; ++j) {
            memoTable[0][j].first = memoTable[0][j - 1].first * grid[0][j];
            memoTable[0][j].second = memoTable[0][j - 1].second * grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            memoTable[i][0].first = memoTable[i - 1][0].first * grid[i][0];
            memoTable[i][0].second = memoTable[i - 1][0].second * grid[i][0];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0) {
                    memoTable[i][j].first = std::min(memoTable[i - 1][j].first, memoTable[i][j - 1].first) * grid[i][j];
                    memoTable[i][j].second = std::max(memoTable[i - 1][j].second, memoTable[i][j - 1].second) * grid[i][j];
                } else {
                    memoTable[i][j].first = std::max(memoTable[i - 1][j].second, memoTable[i][j - 1].second) * grid[i][j];
                    memoTable[i][j].second = std::min(memoTable[i - 1][j].first, memoTable[i][j - 1].first) * grid[i][j];
                }
            }
        }
        if (memoTable[m - 1][n - 1].second >= 0)
            return memoTable[m - 1][n - 1].second % int(1e9 + 7);
        else
            return -1;
    }
};

int main () {
    MaxProductPath mpp;
    std::vector<std::vector<int>> grid = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
    std::cout << mpp.maxProductPath(grid);

    return 0;
}