#include <iostream>
using namespace std;

int n, s;
int inputNum[20], outputNum[20];
int answer;

void dfs(int t, int cnt, int total)
{
	if (t == total)
	{
		int sum = 0;
		for (int i = 0; i < t; ++i)
			sum += outputNum[i];
		if (sum == s)
			answer++;
		return;
	}

	for (int i = cnt; i < n; ++i) 
	{
		outputNum[t] = inputNum[i];
		dfs(t + 1, i + 1, total);
	}
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> inputNum[i];

	for (int i = 1; i <= n; ++i)
		dfs(0, 0, i);

	cout << answer;
}