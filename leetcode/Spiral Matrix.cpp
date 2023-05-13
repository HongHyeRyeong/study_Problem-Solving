#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        bool isStop = false;
        int x = -1, y = 0;
        int dir[4][2]{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        while (isStop == false) {
            isStop = true;
            for (int dirIndex = 0; dirIndex < 4; ++dirIndex) {
                while (true)
                {
                    int nextX = x + dir[dirIndex][1], nextY = y + dir[dirIndex][0];
                    if (0 > nextX || nextX >= matrix[0].size())
                        break;
                    if (0 > nextY || nextY >= matrix.size())
                        break;
                    if (matrix[nextY][nextX] == -1000)
                        break;

                    isStop = false;
                    x = nextX, y = nextY;
                    answer.push_back(matrix[y][x]);
                    matrix[y][x] = -1000;
                }
            }
        }

        return answer;
    }
};