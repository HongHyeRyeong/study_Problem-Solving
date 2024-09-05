#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 1)
            return nums[0];
        else if (size == 2)
            return max(nums[0], nums[1]);

        int dp[2][101]{};

        for (int startIndex = 0; startIndex <= 1; ++startIndex) {
            dp[startIndex][startIndex] = nums[startIndex];
            dp[startIndex][startIndex + 1] = max(nums[startIndex], nums[startIndex + 1]);
            for (int i = startIndex + 2; i < size; ++i)
                dp[startIndex][i] = max(dp[startIndex][i - 1], dp[startIndex][i - 2] + nums[i]);
        }

        return max(dp[0][size - 2], dp[1][size - 1]);
    }
};
