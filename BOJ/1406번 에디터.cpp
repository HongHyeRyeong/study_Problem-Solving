#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	stack<char> StackL, StackR;
	for (int i = 0; i < s.length(); i++)
		StackL.push(s[i]);

	int M;
	cin >> M;
	while (M--) {
		cin >> s;
		if (s == "L") {
			if (!StackL.empty()) {
				StackR.push(StackL.top());
				StackL.pop();
			}
		}
		else if (s == "D") {
			if (!StackR.empty()) {
				StackL.push(StackR.top());
				StackR.pop();
			}
		}
		else if (s == "B") {
			if (!StackL.empty())
				StackL.pop();
		}
		else if (s == "P") {
			char tmp;
			cin >> tmp;
			StackL.push(tmp);
		}
	}

	while (!StackL.empty()) {
		StackR.push(StackL.top());
		StackL.pop();
	}

	while (!StackR.empty()) {
		cout << StackR.top();
		StackR.pop();
	}
}