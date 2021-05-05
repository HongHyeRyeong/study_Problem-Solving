#include <iostream>
using namespace std;

int num[2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		num[tmp + 1000]++;
	}

	for (int i = 0; i < 2001; ++i)
		if (num[i] > 0)
			cout << i - 1000 << " ";
}