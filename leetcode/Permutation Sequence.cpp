#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
            v.push_back(i);

        for (int i = 1; i < k; ++i)
            nextPermutation(v);

        string answer = "";
        for (int i = 0; i < n; ++i)
            answer += to_string(v[i]);
        return answer;
    }

    void nextPermutation(vector<int>& nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;

        if (i == -1)
            reverse(nums.begin(), nums.end());
        else {
            int j = i + 1;
            while (j < nums.size() && nums[i] < nums[j]) j++;
            swap(nums[i], nums[j - 1]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};