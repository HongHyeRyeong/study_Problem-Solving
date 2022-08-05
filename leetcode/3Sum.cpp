#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {
        vector<vector<int>> answers;
        int target;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (target == -nums[i])
                continue;

            target = -nums[i];
            int left = i + 1, right = nums.size() - 1, sum = 0;
            while (left < right)
            {
                sum = nums[left] + nums[right];

                if (target > sum)
                    ++left;
                else if (target < sum)
                    --right;
                else
                {
                    vector<int> temp = {nums[left], -target, nums[right]};
                    answers.push_back(temp);

                    while (left < nums.size() && nums[left] == temp[0])
                        ++left;
                    while (right >= 0 && nums[right] == temp[2])
                        --right;
                }
            }
        }

        return answers;
    }
};