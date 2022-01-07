#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int L, N;
	cin >> L >> N;

	int answer = 1;
	pair<int, int> point{ L + 1, L + 1 }, dir{ 1,0 };
	vector<pair<int, int>> points;
	points.push_back(point);
	while (N--) {
		int t;
		char c;
		cin >> t >> c;

		bool die = false;
		while (t--) {
			point.first += dir.first;
			point.second += dir.second;

			if (point.first == 0 || point.first == 2 * L + 2 || point.second == 0 || point.second == 2 * L + 2) {
				die = true;
				break;
			}

			for (pair<int, int> p : points) {
				if (point == p) {
					die = true;
					break;
				}
			}

			if (die)
				break;

			answer++;
			points.push_back(point);
		}

		if (die)
			break;

		if (c == 'R') {
			if (dir.first == 1 && dir.second == 0)
				dir.first = 0, dir.second = 1;
			else if (dir.first == 0 && dir.second == 1)
				dir.first = -1, dir.second = 0;
			else if (dir.first == -1 && dir.second == 0)
				dir.first = 0, dir.second = -1;
			else if (dir.first == 0 && dir.second == -1)
				dir.first = 1, dir.second = 0;
		}
		else if (c == 'L') {
			if (dir.first == 1 && dir.second == 0)
				dir.first = 0, dir.second = -1;
			else if (dir.first == 0 && dir.second == -1)
				dir.first = -1, dir.second = 0;
			else if (dir.first == -1 && dir.second == 0)
				dir.first = 0, dir.second = 1;
			else if (dir.first == 0 && dir.second == 1)
				dir.first = 1, dir.second = 0;
		}
	}

	cout << answer;
}