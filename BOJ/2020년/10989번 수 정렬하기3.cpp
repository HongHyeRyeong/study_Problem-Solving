#include <iostream>
using namespace std;

int nums[10001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, tmp;
	cin >> N;
	while (N--) {
		cin >> tmp;
		nums[tmp]++;
	}
	for (int i = 1; i <= 10000; ++i)
		for (int j = 0; j < nums[i]; ++j)
			cout << i << endl;
}