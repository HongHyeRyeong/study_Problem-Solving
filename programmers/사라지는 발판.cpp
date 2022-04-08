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

        // 1. 현재 저장된 턴은 패배(짝)인데 새로 계산된 턴은 승리(홀)인 경우
        if (ret % 2 == 0 && nret % 2 == 1)
            ret = nret;
        // 2. 현재 저장된 턴과 새로 계산된 턴이 모두 패배인 경우
        else if (ret % 2 == 0 && nret % 2 == 0)
            ret = max(ret, nret); // 최대한 늦게 지는걸 선택
        // 3. 현재 저장된 턴과 새로 계산된 턴이 모두 승리인 경우
        else if (ret % 2 == 1 && nret % 2 == 1)
            ret = min(ret, nret); // 최대한 빨리 이기는걸 선택
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