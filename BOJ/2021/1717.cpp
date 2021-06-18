#include <iostream>
using namespace std;

int parent[1000001];

int GetParent(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = GetParent(parent[a]);
}


void UnionFind(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);

	if (b < a)
		parent[a] = b;
	else
		parent[b] = a;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0)
			UnionFind(b, c);
		else {
			if (GetParent(b) == GetParent(c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}