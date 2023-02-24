#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> answer;
	int number[10]{};
	bool check[10]{};
	
	void DFS(vector<int>& nums, int t)
	{
		if (t == nums.size()) {
			vector<int> temp;
			for (int i = 0; i < nums.size(); i++)
				temp.push_back(number[i]);
			answer.push_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (!check[i]) {
				check[i] = true;
				number[t] = nums[i];
				DFS(nums, t + 1);
				check[i] = false;
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
		DFS(nums, 0);
		return answer;
    }
};