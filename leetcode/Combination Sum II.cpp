#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> answer;

	void dfs(vector<int>& candidates, int target, vector<int> number, int index)
	{
		if (target == 0) {
			answer.push_back(number);
		}
		else {
			for (int i = index; i < candidates.size(); ++i) {
				if (candidates[i] > target)
					return;
				if (i && candidates[i] == candidates[i - 1] && i > index)
					continue;

				number.push_back(candidates[i]);
				dfs(candidates, target - candidates[i], number, i + 1);
				number.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> number;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, number, 0);

		return answer;
	}
};