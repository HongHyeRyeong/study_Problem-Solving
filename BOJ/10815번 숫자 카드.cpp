#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[10001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, tmp;
	vector<int> v;

	cin >> N;
	while (N--) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cin >> M;
	while (M--)	{
		cin >> tmp;
		cout << binary_search(v.begin(), v.end(), tmp) << " ";
	}
}