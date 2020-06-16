#include <iostream>
using namespace std;

long long dp[100][100]{ 1 };

int main()
{
    int N;
    cin >> N;

    int map[100][100]{};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (dp[i][j] > 0 && map[i][j]) {
                if (i + map[i][j] < N)
                    dp[i + map[i][j]][j] += dp[i][j];
                if (j + map[i][j] < N)
                    dp[i][j + map[i][j]] += dp[i][j];
            }
    cout << dp[N - 1][N - 1];
}