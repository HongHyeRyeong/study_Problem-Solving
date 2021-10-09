#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	int ans = 0, sum = 0;
	int start = 0, end = 0;
	while (1) {
		if (sum >= M)
			sum -= A[start++];
		else if (end == N)
			break;
		else
			sum += A[end++];

		if (sum == M)
			ans++;
	}
	cout << ans;
}