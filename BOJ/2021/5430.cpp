#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		string p, x;
		int n;
		cin >> p >> n >> x;

		deque<string> d;
		for (int i = 2, j = 1; i < x.size(); ++i) {
			if (x[i] == ',' || x[i] == ']') {
				d.push_back(x.substr(j, i - j));
				j = i + 1;
			}
		}

		bool reverse = false, error = false;
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 'R')
				reverse = !reverse;
			else if (p[i] == 'D') {
				if (d.empty()) {
					error = true;
					break;
				}

				if (reverse)
					d.pop_back();
				else
					d.pop_front();
			}
		}

		string answer = "";
		if (error)
			answer = "error";
		else {
			if (reverse) {
				for (auto iter = d.rbegin(); iter != d.rend(); ++iter)
					answer += (*iter) + ",";
			}
			else {
				for (auto iter = d.begin(); iter != d.end(); ++iter)
					answer += (*iter) + ",";
			}

			if (answer.back() == ',')
				answer.pop_back();
			answer = '[' + answer + ']';
		}
		cout << answer << '\n';
	}
}