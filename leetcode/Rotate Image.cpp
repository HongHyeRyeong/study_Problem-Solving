#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size() / 2; ++i)
        {
            for (int j = i; j < matrix.size() - i - 1; ++j)
            {
                int ii = i, jj = j, pre = matrix[ii][jj];
                int dir = 0;

                while (true)
                {
                    if (dir == 0) // 위
                    {
                        ii = j;
                        jj = matrix.size() - 1 - i;
                    }
                    else if (dir == 1) // 오른
                    {
                        ii = matrix.size() - 1 - i;
                        jj = matrix.size() - 1 - j;
                    }
                    else if (dir == 2) // 아래
                    {
                        ii = matrix.size() - 1 - j;
                        jj = i;
                    }
                    else if (dir == 3) // 왼
                    {
                        ii = i;
                        jj = j;
                    }
                    else
                        break;

                    int cur = matrix[ii][jj];
                    matrix[ii][jj] = pre;
                    pre = cur;
                    dir++;
                }
            }
        }
    }
};