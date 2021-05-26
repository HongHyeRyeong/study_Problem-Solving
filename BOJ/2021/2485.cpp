#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> diff(N - 1);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];

		if (i > 0)
			diff[i - 1] = v[i] - v[i - 1];
	}

	int min = 1e9;
	for (int i = 0; i < N - 2; ++i) {
		int tmp = gcd(diff[i], diff[i + 1]);
		if (tmp < min)
			min = tmp;
	}

	cout << (v[N - 1] - v[0]) / min - (N - 1);
}