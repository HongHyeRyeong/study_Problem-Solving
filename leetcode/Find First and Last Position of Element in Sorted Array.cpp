#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> answer;
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            if (nums[start] == target && nums[end] == target)
            {
                answer.push_back(start);
                answer.push_back(end);
                break;
            }
            else if (nums[start] < target)
                start++;
            else
                end--;
        }

        if (answer.empty())
        {
            answer.push_back(-1);
            answer.push_back(-1);
        }

        return answer;
    }
};