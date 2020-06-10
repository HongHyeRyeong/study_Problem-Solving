#include <iostream>
using namespace std;

int main()
{
	int num[41][2]{ {1, 0}, {0, 1} };
	for (int i = 2; i <= 40; ++i) {
		num[i][0] = num[i - 1][0] + num[i - 2][0];
		num[i][1] = num[i - 1][1] + num[i - 2][1];
	}

	int T, tmp;
	cin >> T;
	while (T--) {
		cin >> tmp;
		cout << num[tmp][0] << " " << num[tmp][1] << "\n";
	}
}