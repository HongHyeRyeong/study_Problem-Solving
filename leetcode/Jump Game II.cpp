#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dp[10002]{ };

    int jump(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j)
                if (dp[j] == 0)
                    dp[j] = dp[i] + 1;

        return dp[nums.size() - 1];
    }
};