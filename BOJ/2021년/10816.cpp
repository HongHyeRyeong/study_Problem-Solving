#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a;
	cin >> N;

	unordered_map<int, int> m;
	while (N--) {
		cin >> a;
		m[a]++;
	}

	int M;
	cin >> M;
	while (M--) {
		cin >> a;
		cout << m[a] << " ";
	}
}