#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class info {
public:
	int x, y, p, q;
};

bool cmp(const info& a, const info& b) {
	if (1LL * a.q * b.p != 1LL * b.q * a.p)
		return 1LL * a.q * b.p < 1LL * b.q * a.p;
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}

// ccw: 반시계 방향인지 판단하는 알고리즘
bool ccw(info a, info b, info c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y > 0;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<info> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;

	// 기준이 될 좌표(가장 왼쪽 아래 위치한 좌표)를 인덱스 0에 놓기 위해 정렬을 한다.
	sort(v.begin(), v.end(), cmp);

	// 반시계 방향으로 정렬
	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	sort(v.begin() + 1, v.end(), cmp);

	int index = 2;
	vector<int> polygon;
	polygon.push_back(0), polygon.push_back(1);
	while (index < n) {
		while (polygon.size() >= 2) {
			// 가장 가까운 점 2개와 새로운 점 하나를 가져와 반시계 방향인지 확인한다.
			int second = polygon.back();
			polygon.pop_back();
			int first = polygon.back();

			if (ccw(v[first], v[second], v[index])) {
				polygon.push_back(second);
				break;
			}
		}
		polygon.push_back(index++);
	}

	cout << polygon.size();
}