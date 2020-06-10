#include <iostream>
using namespace std;

int pos[100001];
int diff[100000];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> pos[i];
		if (i > 1)
			diff[i - 1] = pos[i] - pos[i - 1];
	}

	int min = 1e10;
	for (int i = 1; i < N; ++i) {
		int tmp = gcd(diff[i], diff[i - 1]);
		if (tmp < min)
			min = tmp;
	}
	cout << (pos[N] - pos[1]) / min - N + 1;
}