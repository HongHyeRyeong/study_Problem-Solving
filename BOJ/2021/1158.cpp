#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 0; i < N; ++i)
		q.push(i + 1);

	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < K; ++i) {
			if (i == K - 1)
				cout << q.front() << ", ";
			else
				q.push(q.front());

			q.pop();
		}
	}
	cout << q.front() << ">";
}