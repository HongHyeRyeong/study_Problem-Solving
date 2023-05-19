#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i <= j; ++i) {
            j = max(j, i + nums[i]);
            if (j >= nums.size() - 1)
                return true;
        }
        return false;
    }
};