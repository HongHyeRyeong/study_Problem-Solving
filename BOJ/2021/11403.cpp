#include <iostream> 
using namespace std;

int main()
{
	int N;
	cin >> N;

	bool graph[100][100];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	// �ٸ� ������ ���� �� �� ���� �� 1�� ����
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (graph[i][k] && graph[k][j])
					graph[i][j] = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << (int)graph[i][j] << ' ';
		cout << '\n';
	}
}