#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int m = 0, n = 0;
    int dir[4][2]{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int check[202][202]{};

    bool dfs(vector<vector<char>>& board, int x, int y)
    {
        check[y][x] = true;

        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (0 > newX || newX >= n || 0 > newY || newY >= m)
                return false;
            if (check[newY][newX])
                continue;
            if (board[newY][newX] == 'O' && dfs(board, newX, newY) == false)
                return false;
        }

        return true;
    }

    void change(vector<vector<char>>& board, int x, int y)
    {
        board[y][x] = 'X';

        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (0 > newX || newX >= n || 0 > newY || newY >= m)
                continue;
            if (board[newY][newX] == 'X')
                continue;

            change(board, newX, newY);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'O') {
                    for (int a = 0; a < 202; ++a)
                        for (int b = 0; b < 202; ++b)
                            check[a][b] = false;

                    if (dfs(board, j, i))
                        change(board, j, i);
                }
    }
};