#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	string s;
	cin >> s;

	deque<char> front, back;
	for (char c : s)
		front.push_back(c);

	int M;
	cin >> M;
	while (M--) {
		char order;
		cin >> order;

		if (order == 'L') {
			if (!front.empty()) {
				back.push_front(front.back());
				front.pop_back();
			}
		}
		else if (order == 'D') {
			if (!back.empty()) {
				front.push_back(back.front());
				back.pop_front();
			}
		}
		else if (order == 'B') {
			if (!front.empty()) {
				front.pop_back();
			}
		}
		else if (order == 'P') {
			char input;
			cin >> input;
			front.push_back(input);
		}
	}

	for (char c : front)
		cout << c;
	for (char c : back)
		cout << c;
}