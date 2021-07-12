#include <iostream>
using namespace std;

void hanoi(int n, int from, int mid, int to)
{
	if (n == 1)
		cout << from << ' ' << to << '\n';
	else {
		hanoi(n - 1, from, to, mid);
		cout << from << ' ' << to << '\n';
		hanoi(n - 1, mid, from, to);
	}
}

int main()
{
	int k;
	cin >> k;

	cout << (1 << k) - 1 << '\n'; // 2^n - 1
	hanoi(k, 1, 2, 3);
}