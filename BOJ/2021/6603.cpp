#include <iostream>
using namespace std;

int k;
int inputNum[12], outputNum[12];
bool ckeck[12];

void DFS(int t, int cnt)
{
	if (t == 6) {
		for (int i = 0; i < 6; i++)
			cout << outputNum[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = cnt; i < k; i++) {
		outputNum[t] = inputNum[i];
		DFS(t + 1, i + 1);
	}
}

int main()
{
	while (cin >> k) {
		if (k == 0)
			break;

		for (int i = 0; i < k; ++i)
			cin >> inputNum[i];
		
		DFS(0, 0);
		cout << '\n';
	}
}