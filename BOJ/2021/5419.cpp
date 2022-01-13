#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Point {
public:
	int x, y;
	int index; // xÁÂÇ¥ Å©±â ¼øÀ§
};

int sum(vector<int>& tree, int index)
{
	int ans = 0;
	while (index > 0) {
		ans += tree[index];
		index -= (index & -index);
	}
	return ans;
}

void update(vector<int>& tree, int index, int value)
{
	while (index < tree.size()) {
		tree[index] += value;
		index += (index & -index);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<Point> v;
		vector<int> tree(n + 1);
		for (int i = 0; i < n; i++) {
			Point data;
			cin >> data.x >> data.y;
			v.push_back(data);
			update(tree, i + 1, 1); // ÆæÀ¨Æ®¸® °»½Å
		}

		// ÁÂÇ¥ ¾ĞÃà
		sort(v.begin(), v.end(), [](auto& a, auto& b) {
			if (a.x == b.x)
				return a.y > b.y;
			return a.x < b.x;
			});

		for (int i = 0; i < n; i++)
			v[i].index = i;

		sort(v.begin(), v.end(), [](auto& a, auto& b) {
			if (a.y == b.y)
				return a.x < b.x;
			return a.y > b.y;
			});

		// ÆæÀ¨Æ®¸® 
		long long total = 0;
		for (int i = 0; i < v.size(); i++) {
			total += sum(tree, n) - sum(tree, v[i].index + 1);
			update(tree, v[i].index + 1, -1);
		}
		cout << total << "\n";
	}
}