#include <vector>
using namespace std;

vector<vector<int>> block;

int width, height;
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };

int dfs(int curx, int cury, int opx, int opy)
{
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = curx + dir[i][0], ny = cury + dir[i][1];
        if (nx < 0 || nx >= width || ny < 0 || ny >= height || !block[nx][ny])
            continue;

        block[curx][cury] = 0;
        int nret = (block[opx][opy] ? dfs(opx, opy, nx, ny) : 0) + 1;
        block[curx][cury] = 1;

        // 1. ���� ����� ���� �й�(¦)�ε� ���� ���� ���� �¸�(Ȧ)�� ���
        if (ret % 2 == 0 && nret % 2 == 1)
            ret = nret;
        // 2. ���� ����� �ϰ� ���� ���� ���� ��� �й��� ���
        else if (ret % 2 == 0 && nret % 2 == 0)
            ret = max(ret, nret); // �ִ��� �ʰ� ���°� ����
        // 3. ���� ����� �ϰ� ���� ���� ���� ��� �¸��� ���
        else if (ret % 2 == 1 && nret % 2 == 1)
            ret = min(ret, nret); // �ִ��� ���� �̱�°� ����
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    block = board;
    width = board.size();
    height = board[0].size();
    return dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
}