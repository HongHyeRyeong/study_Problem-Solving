class Solution {
public:
    vector<vector<int>> answer;

    void dfs(int index, vector<int> v, vector<int>& nums) {
        answer.push_back(v);
        int num = -11;
        for (int i = index; i < nums.size(); ++i) {
            if (num != nums[i]) {
                vector<int> vv = v;
                vv.push_back(nums[i]);
                dfs(i + 1, vv, nums);
                num = nums[i];
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(0, v, nums);
        return answer;
    }
};