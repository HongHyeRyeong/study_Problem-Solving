#include <iostream>
using namespace std;

int main()
{
	char s[20][20]{};
	char deco[2]{ '#','.' };
	bool b = false;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j)
			s[i][j] = deco[b], b = !b;
		b = !b;
	}

	int M, N, U, L, R, D;
	cin >> M >> N >> U >> L >> R >> D;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> s[i + U][j + L];

	for (int i = 0; i < M + U + D; ++i) {
		for (int j = 0; j < N + L + R; ++j)
			cout << s[i][j];
		cout << '\n';
	}
}