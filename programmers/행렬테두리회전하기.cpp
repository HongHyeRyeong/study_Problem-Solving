#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];

int Rotate(int rows, int columns, int x1, int y1, int x2, int y2)
{
    int minValue = 1e9;

    int temp[101][101]{};
    for (int i = 1; i <= rows; ++i)
        for (int j = 1; j <= columns; ++j)
            temp[i][j] = map[i][j];

    // 위
    for (int i = y1 + 1; i <= y2; ++i) {
        map[x1][i] = temp[x1][i - 1];
        minValue = min(minValue, map[x1][i]);
    }

    // 아래
    for (int i = y1; i < y2; ++i) {
        map[x2][i] = temp[x2][i + 1];
        minValue = min(minValue, map[x2][i]);
    }

    // 왼쪽
    for (int i = x1; i < x2; ++i) {
        map[i][y1] = temp[i + 1][y1];
        minValue = min(minValue, map[i][y1]);
    }

    // 오른쪽
    for (int i = x1 + 1; i <= x2; ++i) {
        map[i][y2] = temp[i - 1][y2];
        minValue = min(minValue, map[i][y2]);
    }

    return minValue;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    int num = 1;
    for (int i = 1; i <= rows; ++i)
        for (int j = 1; j <= columns; ++j)
            map[i][j] = num++;

    for (int i = 0; i < queries.size(); ++i)
        answer.push_back(Rotate(rows, columns, queries[i][0], queries[i][1], queries[i][2], queries[i][3]));

    return answer;
}