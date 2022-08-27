#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answers;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int left = j + 1, right = nums.size() - 1, sum = target - (nums[i] + nums[j]);
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (target > sum)
                        ++left;
                    else if (target < sum)
                        --right;
                    else
                    {
                        vector<int> temp = { nums[i], nums[j], nums[left], nums[right] };
                        answers.push_back(temp);

                        while (left < nums.size() - 1 && nums[left + 1] == nums[left]) ++left;
                        while (right > 0 && nums[right - 1] == nums[left]) --right;
                        ++left;
                        --right;
                    }
                }
                while (j < nums.size() - 1 && nums[j + 1] == nums[j]) j++;
            }
            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) i++;
        }

        return answers;
    }
};