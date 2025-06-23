/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively. 

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [[Q]]
*/

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class NQueens {
public:
    bool isCorrectPosition (std::vector<std::string> queens, int n, int row, int col) {
        // Check for the rows
        for (int l = 0; l < n; l++)
            if (queens[row][l] == 'Q')
                return false;

        // Check for the columns
        for (int l = 0; l < n; l++)
            if (queens[l][col] == 'Q')
                return false;
        
        // Check diagonals
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (queens[i][j] == 'Q')
                return false;
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (queens[i][j] == 'Q')
                return false;
        
        return true;
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> queens(n, std::string(n, '.'));

        auto backtrack = [&](int row, auto&& self) {
            if (row == n) {
                result.push_back(queens);
                return;
            }

            for (int col = 0; col < n; col++) {
                if (isCorrectPosition(queens, n, row, col)) {
                    queens[row][col] = 'Q';
                    self(row + 1, self);
                    queens[row][col] = '.';
                }
            }
        };

        backtrack(0, backtrack);
        return result;
    }
};

int main () {
    NQueens nq;
    int n = 4;
    std::vector<std::vector<std::string>> output = nq.solveNQueens(n);

    for (auto vecSti : output) {
        for (auto str : vecSti)
            std::cout << str << " ";

            std::cout << std::endl;
    }

    return 0;
}