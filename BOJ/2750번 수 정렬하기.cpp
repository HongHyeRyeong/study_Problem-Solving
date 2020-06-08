#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, tmp;
	cin >> N;
	multiset<int> s;
	while (N--) {
		cin >> tmp;
		s.insert(tmp);
	}
	for (int i : s)
		cout << i << endl;
}