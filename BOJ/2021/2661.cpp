#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(int index, string s)
{
	if (index == N) {
		cout << s;
		exit(0);
	}

	for (int i = 1; i <= 3; ++i) {
		string tmp = s + to_string(i);

		bool good = true;
		for (int j = 1, k = tmp.size() - 1; j <= tmp.size() / 2; ++j, --k)
			if (tmp.substr(k, j) == tmp.substr(k - j, j)) {
				good = false;
				break;
			}

		if (good)
			dfs(index + 1, tmp);
	}
}

int main()
{
	cin >> N;
	dfs(0, "");
}