#include <iostream>
#include <algorithm>
using namespace std;

int n, s, cnt, ans;
int num[20], a[20];
bool ck[20];

void f(int t, int c)
{
	if (t == cnt) {
		int sum = 0;
		for (int i = 0; i < cnt; i++)
			sum += a[i];
		if (sum == s)
			ans++;
		return;
	}

	for (int i = c; i < n; i++) {
		if (!ck[i]) {
			ck[i] = true;
			a[t] = num[i];
			f(t + 1, i + 1);
			ck[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	cnt = n + 1;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	while (--cnt) {
		f(0, 0);
		for (int i = 0; i < n; ++i)
			ck[i] = false;
	}
	cout << ans;
}