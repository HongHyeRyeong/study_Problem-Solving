#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int num[50];
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	sort(num, num + n);

	cout << num[0] * num[n - 1];
}