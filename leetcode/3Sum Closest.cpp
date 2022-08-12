#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int closest = 1e9, num1 = 1e9;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (num1 == nums[i])
                continue;

            num1 = nums[i];
            int num2 = i + 1, num3 = nums.size() - 1, sum = 0;
            while (num2 < num3)
            {
                sum = num1 + nums[num2] + nums[num3];

                int diff1 = abs(sum - target);
                int diff2 = abs(closest);
                closest = diff1 < diff2 ? sum - target : closest;

                if (sum < target)
                    ++num2;
                else if (sum > target)
                    --num3;
                else
                {
                    vector<int> temp = { nums[num2], nums[num3] };
                    while (num2 < nums.size() && nums[num2] == temp[0])
                        ++num2;
                    while (num3 >= 0 && nums[num3] == temp[1])
                        --num3;
                }
            }
        }

        return target + closest;
    }
};