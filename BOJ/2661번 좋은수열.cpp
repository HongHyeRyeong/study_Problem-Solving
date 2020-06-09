#include <iostream>
#include <string>
using namespace std;

int N;

void f(int index, string s)
{
	if (index == N) {
		cout << s;
		exit(0);
	}

	for (int i = 1; i <= 3; ++i) {
		string tmp = s + to_string(i);

		bool good = true;
		int len = tmp.size(), start = len - 1, end = len;
		for (int j = 1; j <= len / 2; ++j) {
			if (tmp.substr(start, j) == tmp.substr(start - j, j)) {
				good = false;
				break;
			}
			start--;
		}

		if (good)
			f(index + 1, tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	f(0, "");
}