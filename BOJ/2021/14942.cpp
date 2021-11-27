#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> energys;
vector<pair<int, int>> tunnels[100001];

int parent[100001][20]; // 정점 i에서 2^j번 이동한 후의 정점
int dist[100001][20]; // 정점 i에서 parent[i][j]로 이동하는데 필요한 에너지

void dfs(int start, int index) 
{
    parent[start][0] = index;
    for (pair<int, int> next : tunnels[start])
        if (next.first != index) {
            dist[next.first][0] = next.second;
            dfs(next.first, start);
        }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    energys.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> energys[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tunnels[a].push_back({ b, c });
        tunnels[b].push_back({ a, c });
    }

    // 개미굴을 트리 구조로 만들어 초기화한다.
    dfs(1, 0);

    // 2진수 이동 값을 배열에 채운다.
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++) {
            dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1];
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }

    for (int i = 0; i < n; i++) {
        int pos = i + 1, energy = energys[i];
        for (int j = 20 - 1; j >= 0; j--) {
            if (parent[pos][j] != 0 && energy >= dist[pos][j]) {
                energy -= dist[pos][j];
                pos = parent[pos][j];
            }
        }
        cout << pos << '\n';
    }
}