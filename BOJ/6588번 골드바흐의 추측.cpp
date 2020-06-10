#include <iostream>
#include <vector>
using namespace std;

bool prime[1000001] = { true, true };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 1000000; ++i)
		if (!prime[i])
			for (int j = i * i; j <= 1000000; j += i)
				prime[j] = true;

	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; ++i)
			if (!prime[i] && !prime[N - i]) {
				cout << N << " = " << i << " + " << N - i << "\n";
				break;
			}
	}
}