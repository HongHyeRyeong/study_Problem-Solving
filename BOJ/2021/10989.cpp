#include <iostream>
using namespace std;

int num[10001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a;
	cin >> N;
	while (N--)	{
		cin >> a;
		num[a]++;
	}

	for (int i = 1; i <= 10000; ++i)
		for (int j = 0; j < num[i]; ++j)
			cout << i << '\n';
}