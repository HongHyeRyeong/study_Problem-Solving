#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> answer;

	void DFS(int idx, int count, vector<int>& number, int k, int n) {
		if (idx == k) {
			int sum = 0;
			for (int i = 0; i < k; i++)
				sum += number[i];

			if (sum == n)
				answer.push_back(number);
			return;
		}

		for (int i = count; i <= 9; i++) {
			number[idx] = i;
			DFS(idx + 1, i + 1, number, k, n);
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> number(k);
		DFS(0, 1, number, k, n);
		return answer;
	}
};
