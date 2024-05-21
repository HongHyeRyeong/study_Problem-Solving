#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int dp[201][201]{};

    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if (i == m - 1)
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                else if (j == n - 1)
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                else
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};
