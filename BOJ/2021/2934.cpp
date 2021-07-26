#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> tree(200001);

int sum(int index)
{
	int res = 0;

	// index�� �������� ��Ÿ�� �� ��Ʈ �� 1�� ������ ������
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

		// �⺻ ����
		// [a, b] ������ 1�� ���Ϸ���
		// a���� 1�� ���� �� (update(a, 1)) b+1���� -1�� ���� �ȴ�. (update(b+1, -1))

		// ���� �� ������ �ٽ� ���� �����Ƿ� 0���� �����.		
		update(a, -sumA); // a�� -sumA�� ����ȴ�.
		update(a + 1, sumA);		
		update(b, -sumB); // b�� -sumB�� ����ȴ�.
		update(b + 1, sumB);

		// ���� �ʼ��ִ� ������ 1�� �ִ´�.
		update(a + 1, 1); // a~b�� 1�� ���Ѵ�.
		update(b, -1);
	}
}