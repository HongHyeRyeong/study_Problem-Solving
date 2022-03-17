#include <vector>
using namespace std;

int PrefixSum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    // 2���� �迭 ������
    for (vector<int> sk : skill) {
        int degree = sk[5] * (sk[0] == 1 ? -1 : 1);
        PrefixSum[sk[1]][sk[2]] += degree;
        PrefixSum[sk[1]][sk[4] + 1] -= degree;
        PrefixSum[sk[3] + 1][sk[2]] -= degree;
        PrefixSum[sk[3] + 1][sk[4] + 1] += degree;
    }

    // ������ �Ʒ��� ������
    for (int i = 0; i < board.size(); i++)
        for (int j = 1; j < board[0].size(); j++)
            PrefixSum[i][j] += PrefixSum[i][j - 1];

    // ���ʿ��� ���������� ������
    for (int i = 1; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            PrefixSum[i][j] += PrefixSum[i - 1][j];

    int answer = 0;
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            if (board[i][j] + PrefixSum[i][j] > 0)
                answer++;

    return answer;
}