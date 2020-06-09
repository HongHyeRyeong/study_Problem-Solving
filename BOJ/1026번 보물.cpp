#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int tmp;
	int num1[50], num2[50];
	for (int i = 0; i < N; ++i)
		cin >> num1[i];
	for (int i = 0; i < N; ++i)
		cin >> num2[i];

	sort(num1, num1 + N);
	sort(num2, num2 + N, greater<int>());

	int ans = 0;
	for (int i = 0; i < N; ++i)
		ans += num1[i] * num2[i];
	cout << ans;
}