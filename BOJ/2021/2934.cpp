#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> tree(200001);

int sum(int index)
{
	int res = 0;

	// index를 이진수로 나타낸 뒤 비트 내 1이 없어질 때까지
	// index(111) = 7, 6, 4
	while (index > 0) {
		res += tree[index];
		index -= index & -index;
	}

	return res;
}

void update(int index, int num) 
{
	while (index <= tree.size()) {
		tree[index] += num;
		index += index & -index;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;

		int sumA = sum(a), sumB = sum(b);
		cout << sumA + sumB << '\n';

		// 기본 원리
		// [a, b] 구간에 1을 더하려면
		// a부터 1을 더한 후 (update(a, 1)) b+1부터 -1을 빼면 된다. (update(b+1, -1))

		// 꽃이 핀 곳에는 다시 피지 않으므로 0으로 만든다.		
		update(a, -sumA); // a만 -sumA가 적용된다.
		update(a + 1, sumA);		
		update(b, -sumB); // b만 -sumB가 적용된다.
		update(b + 1, sumB);

		// 꽃이 필수있는 구간에 1을 넣는다.
		update(a + 1, 1); // a~b에 1을 더한다.
		update(b, -1);
	}
}