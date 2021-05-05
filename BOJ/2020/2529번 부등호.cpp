#include <iostream>
#include <string>
using namespace std;

// 입력
int k;
char c[9];

string Max = "0", Min = "9999999999";
int num[10];
bool ck[10];

// 올바른 부등호?
bool correct()
{
	for (int i = 0; i < k; ++i) {
		if (c[i] == '<' && num[i] > num[i + 1])
			return false;
		else if (c[i] == '>' && num[i] < num[i + 1])
			return false;
	}
	return true;
}

// 백트래킹을 이용해 숫자 뽑기
void DFS(int cnt)
{
	if (cnt == k + 1) {
		if (correct()) {
			string tmp = ""; // 0 때문에 string으로 저장
			for (int i = 0; i <= k; ++i)
				tmp += to_string(num[i]);

			if (tmp < Min)
				Min = tmp;
			if (Max < tmp)
				Max = tmp;
		}
	}

	for (int i = 0; i < 10; ++i)
		if (!ck[i]) {
			ck[i] = true;
			num[cnt] = i;
			DFS(cnt + 1);
			ck[i] = false;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> c[i];

	DFS(0);
	cout << Max << '\n' << Min;
}