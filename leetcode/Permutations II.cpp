#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> answer;
	int number[10]{};
	unordered_map<int, int> check;

	void DFS(vector<int>& nums, int t)
	{
		if (t == nums.size()) {
			vector<int> temp;
			for (int i = 0; i < nums.size(); i++)
				temp.push_back(number[i]);
			answer.push_back(temp);
			return;
		}

		for (auto iter = check.begin(); iter != check.end(); ++iter) {
			if (iter->second != 0) {
				iter->second -= 1;
				number[t] = iter->first;
				DFS(nums, t + 1);
				iter->second += 1;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
			check[nums[i]]++;

		DFS(nums, 0);
		return answer;
	}
};