#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, P;
int machine[16][16];
int dp[1 << 16];

int GetOnCount(int n)
{
    if (n == 0)
        return 0;
    return GetOnCount(n >> 1) + (n & 1);
}

int GetMinCost(int state)
{
    int& result = dp[state];

    if (result != -1)
        return result;
    if (GetOnCount(state) >= P)
        return 0;

    result = 1e9;

    for (int i = 0; i < N; i++)
        if ((state & (1 << i))) { // �۵� ���� ������(on)
            for (int j = 0; j < N; j++) {
                if ((state & (1 << j)) == 0) { // ���峭 ������(off)
                    // on �����Ⱑ off ������ �۵�
                    result = min(result, machine[i][j] + GetMinCost(state | (1 << j)));
                }
            }
        }

    return result;
}

int main()
{
    string onoff;

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> machine[i][j];
    cin >> onoff >> P;

    int on = 0; // ���� �۵� ���� ������ �ѹ� ��Ʈ ����
    for (int i = 0; i < N; i++)
        if (onoff[i] == 'Y')
            on |= (1 << i); // i��° ��Ʈ�� 1(on) ����

    if (GetOnCount(on) >= P)
    {
        cout << 0;
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    int result = GetMinCost(on);
    if (result == 1e9)
        cout << -1;
    else
        cout << result;
}