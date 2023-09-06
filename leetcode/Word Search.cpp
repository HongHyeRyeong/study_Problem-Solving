#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> _board;
    string _word;

    int dir[4][2]{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    bool dfs(int x, int y, string s, int check[6][6]) {
        if (s == _word)
            return true;
        if (s != _word.substr(0, s.size()))
            return false;

        bool answer = false;
        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (0 > newX || newX >= _board[0].size() || 0 > newY || newY >= _board.size())
                continue;
            if (check[newY][newX])
                continue;

            check[newY][newX] = true;
            answer = answer || dfs(newX, newY, s + _board[newY][newX], check);
            check[newY][newX] = false;
        }
        return answer;
    }


    bool exist(vector<vector<char>>& board, string word) {
        _board = board;
        _word = word;

        for (int y = 0; y < _board.size(); ++y) {
            for (int x = 0; x < _board[0].size(); ++x) {
                string s;
                s += _board[y][x];
                int check[6][6]{};
                check[y][x] = true;
                if (dfs(x, y, s, check))
                    return true;
            }
        }

        return false;
    }
};