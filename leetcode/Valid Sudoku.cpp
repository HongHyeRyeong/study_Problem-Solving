#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudokuLine(vector<char>& board) 
    {
        unordered_set<char> check;

        for (char value : board) {
            if (value == '.')
                continue;

            if (check.find(value) != check.end()) 
                return false;
            check.insert(value);
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<char> boardLine1, boardLine2;

        for (int i = 0; i < 9; i++) {
            boardLine1.clear();
            boardLine2.clear();

            for (int j = 0; j < 9; j++) {
                boardLine1.push_back(board[i][j]);
                boardLine2.push_back(board[j][i]);
            }

            if (isValidSudokuLine(boardLine1) == false || isValidSudokuLine(boardLine2) == false)
                return false;
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                boardLine1.clear();

                for (int k = 0; k < 3; k++)
                    for (int h = 0; h < 3; h++)
                        boardLine1.push_back(board[i * 3 + k][j * 3 + h]);

                if (isValidSudokuLine(boardLine1) == false)
                    return false;
            }

        return true;
    }
};