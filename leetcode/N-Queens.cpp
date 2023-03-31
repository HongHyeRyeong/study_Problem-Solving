#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> answer;
    int check[9];

    bool IsValid(int row)
    {
        for (int i = 0; i < row; i++)
            if (check[row] == check[i] || abs(check[row] - check[i]) == abs(row - i))
                return false;
        return true;
    }

    void DFS(int n, int row)
    {
        if (n == row) {
            vector<string> temp;
            for (int i = 0; i < n; ++i) {
                string s = "";
                for (int j = 0; j < n; ++j)
                    s += (check[i] == j ? "Q" : ".");
                temp.push_back(s);
            }
            answer.push_back(temp);
            return;
        }

        for (int i = 0; i < n; ++i) {
            check[row] = i;
            if (IsValid(row))
                DFS(n, row + 1);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        DFS(n, 0);
        return answer;
    }
};