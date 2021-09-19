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
        if ((state & (1 << i))) { // 작동 중인 발전기(on)
            for (int j = 0; j < N; j++) {
                if ((state & (1 << j)) == 0) { // 고장난 발전기(off)
                    // on 발전기가 off 발전기 작동
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

    int on = 0; // 현재 작동 중인 발전기 넘버 비트 저장
    for (int i = 0; i < N; i++)
        if (onoff[i] == 'Y')
            on |= (1 << i); // i번째 비트에 1(on) 삽입

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