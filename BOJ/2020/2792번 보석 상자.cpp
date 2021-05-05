#include <iostream>
#include <algorithm>
using namespace std;

int gem[300000];

int main(void)
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> gem[i];

	int start = 1, end = *max_element(gem, gem + M), mid;
	while (start <= end) {
		mid = (start + end) / 2;

		int tmp = 0;
		for (int i = 0; i < M; ++i) {
			tmp += gem[i] / mid;
			if (gem[i] % mid)
				tmp++;
		}

		if (N < tmp)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << start;
}