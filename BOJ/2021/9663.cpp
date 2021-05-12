#include <iostream>
using namespace std;

int n, ans;
bool row[15], right_diagonal[30], left_diagonal[30];

void n_queen(int cnt) {
	if (cnt == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (row[i] || right_diagonal[i + cnt] || left_diagonal[n - 1 - i + cnt])
			continue;

		row[i] = right_diagonal[i + cnt] = left_diagonal[n - 1 - i + cnt] = true;
		n_queen(cnt + 1);
		row[i] = right_diagonal[i + cnt] = left_diagonal[n - 1 - i + cnt] = false;
	}
}

int main()
{
	cin >> n;
	n_queen(0);
	cout << ans;
}