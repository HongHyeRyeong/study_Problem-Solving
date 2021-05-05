#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string s)
{
	stack<char> stack;

	for (char c : s) {
		if (c == '(')
			stack.push(c);
		else {
			if (stack.empty())
				return false;
			stack.pop();
		}
	}

	return stack.empty();
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		if (check(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}