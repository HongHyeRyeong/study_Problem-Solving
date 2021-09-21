#include <iostream>
#include <vector>
using namespace std;

void sol1()
{
    // �ð� �ʰ��� �޸� �ʰ��� �ȳ��µ�
    // �� ����� �� �ȵǴ��� �𸣰ڴ�

    const int MOVE = 500;
    int f[200001][MOVE]; // f[j][i]: j���� i�� ������ ��

    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> f[i][0];

    for (int i = 1; i < MOVE; ++i)
        for (int j = 1; j <= m; ++j)
            f[j][i] = f[f[j][i - 1]][0];

    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;
        n--; // [0 ~ MOVE-1] ���� ��� ���̱� ������ -1 �Ѵ�.

        for (int index = MOVE; index < n; index += MOVE)
            x = f[x][MOVE - 1];

        cout << f[x][n % MOVE] << '\n';
    }
}

int f2[200001][20]; // f[j][i]: j���� 2^i�� ������ ��

void sol2()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> f2[i][0];

    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= m; i++)
            f2[i][j] = f2[f2[i][j - 1]][j - 1];

    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;

        for (int i = 0; 0 < n; i++) {
            // �ش�Ǵ� ��Ʈ�� �ǳʶڴ�.
            if (n & 1)
                x = f2[x][i];
            n >>= 1;
        }

        cout << x << '\n';
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    sol2();
}