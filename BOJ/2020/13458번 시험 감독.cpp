#include <iostream>
using namespace std;

int num[1000000];

int main(void)
{
	int N, B, C;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	cin >> B >> C;

	long long ans = N;
	for (int i = 0; i < N; ++i) {
		num[i] -= B;
		if (num[i] > 0)
			ans += num[i] % C ? num[i] / C + 1 : num[i] / C;
	}
	cout << ans;
}