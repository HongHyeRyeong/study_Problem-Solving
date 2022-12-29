#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> answer;

	void dfs(vector<int>& candidates, int target, vector<int> number, int index)
	{
		if (target == 0)
			answer.push_back(number);
		if (target < 0)
			return;

		while (index < candidates.size()) {
			number.push_back(candidates[index]);
			dfs(candidates, target - candidates[index], number, index++);
			number.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> number;
		dfs(candidates, target, number, 0);
		return answer;
	}
};