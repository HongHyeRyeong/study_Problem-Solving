#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;

    void dfs(int index, vector<int> v, vector<int>& nums) {
        answer.push_back(v);
        for (int i = index; i < nums.size(); ++i) {
            vector<int> vv = v;
            vv.push_back(nums[i]);
            dfs(i + 1, vv, nums);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(0, v, nums);
        return answer;
    }
};