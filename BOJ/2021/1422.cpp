#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int K, N;
	cin >> K >> N;

	int maxLength = 0;
	vector<string> v(K);
	for (int i = 0; i < K; ++i) {
		cin >> v[i];
		maxLength = max(maxLength, (int)v[i].length());
	}

	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		return a + b > b + a;
		});

	for (int i = 0, j = N - K; i < K; ++i) {
		while (maxLength == (int)v[i].length() && j-- > 0)
			cout << v[i];
		cout << v[i];
	}
}