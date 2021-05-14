#include <iostream>
using namespace std;

int main()
{
	bool nums[1000001]{ 1,1 };
	for (int i = 2; i * i <= 1000000; ++i)
		if (!nums[i])
			for (int j = i * i; j <= 1000000; j += i)
				nums[j] = true;

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; ++i)
		if (!nums[i])
			cout << i << '\n';
}