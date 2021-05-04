#include <iostream>
#include <algorithm>
using namespace std;

int num[500000];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, a;

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];

	sort(num, num + N);

	cin >> M;
	while (M--) {
		cin >> a;

		if (binary_search(num, num + N, a))
			cout << "1 ";
		else
			cout << "0 ";
	}
}