#include <iostream>
#include <vector>
using namespace std;

int N, ans;
vector<pair<int, int>> v(16);

void f(int day, int sum)
{
	if (ans < sum)
		ans = sum;

	for (int i = day + v[day].first; i <= N; ++i)
		if (i + v[i].first <= N + 1)
			f(i, sum + v[i].second);
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> v[i].first >> v[i].second;

	for (int i = 1; i <= N; ++i)
		if (i + v[i].first <= N + 1)
			f(i, v[i].second);
	cout << ans;
}