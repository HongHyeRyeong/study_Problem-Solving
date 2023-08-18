#include <vector>
using namespace std;

class Solution {
public:
	int n1, k1;
	int number[21];
    vector<vector<int>> answer;

	void dfs(int t, int cnt)
	{
		if (t == k1) {
			vector<int> v;
			for (int i = 0; i < k1; i++)
				v.push_back(number[i]);
			answer.push_back(v);
			return;
		}

		for (int i = cnt; i <= n1; i++) {
			number[t] = i;
			dfs(t + 1, i + 1);
		}
	}

	vector<vector<int>> combine(int n, int k) {
		n1 = n;
		k1 = k;
		dfs(0, 1);
		return answer;
	}
};