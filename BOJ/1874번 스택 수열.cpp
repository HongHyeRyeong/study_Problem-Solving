#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> s;
	vector<char> v;
	int num = 0, tmp;
	while (n--) {
		cin >> tmp;
		while (s.empty() || s.top() < tmp) {
			if (num > tmp) {
				cout << "NO\n";
				return 0;
			}
			s.push(++num);
			v.push_back('+');
		}
		if (s.top() >= tmp) {
			s.pop();
			v.push_back('-');
		}
	}
	for (char c : v)
		cout << c << "\n";
}