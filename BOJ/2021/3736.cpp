#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000;
const int INF = 1000000000;

int N;
// A[i], B[i]: �׷��� i�� ������ ��Ī�� ����� �׷� ���� ��ȣ
// dist[i]: (A�׷���) i�� ������ ����(?)
// used: (A�׷���) �� ������ ��Ī�� ���� �ִ°�?
int A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

void bfs()
{
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        // ��Ī�� �� ���� A�׷��� ������ ���� 0�� ä�� ����
        if (!used[i]) {
            dist[i] = 0;
            Q.push(i);
        }
        else
            dist[i] = INF;
    }

    // A�׷� ������ 0, 1, 2, 3, ... �� ������ �ű�
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (int b : adj[a]) {
            if (B[b] != -1 && dist[B[b]] == INF) {
                dist[B[b]] = dist[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}

// �̺� ��Ī �˰���
bool dfs(int a)
{
    for (int b : adj[a]) {
        // �̺� ��Ī�� ������: dist �迭�� ���� ������ �߰��� ����
        if (B[b] == -1 || dist[B[b]] == dist[a] + 1 && dfs(B[b])) {
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    while (cin >> N) {
        // Init
        fill(A, A + MAX, -1);
        fill(B, B + MAX, -1);
        fill(used, used + MAX, false);
        for (int i = 0; i < N; i++)
            adj[i].clear();

        // Input
        for (int i = 0; i < N; i++) {
            int job, server, M;
            scanf("%d: (%d)", &job, &M);
            for (int j = 0; j < M; j++) {
                cin >> server;
                adj[job].push_back(server - N);
            }
        }

        // ȣ��ũ����Ʈ ī�� �˰���
        int answer = 0;
        while (1) {
            // �� ������ ������ �ű�� ����
            bfs();

            // �̺� ��Ī �˰����� �̿��� ���� ��� ã��
            int flow = 0;
            for (int i = 0; i < N; i++)
                if (!used[i] && dfs(i))
                    flow++;
            answer += flow;

            // �� �̻� ���� ��θ� �� ã���� �˰��� ����
            if (flow == 0)
                break;
        }

        cout << answer << '\n';
    }
}