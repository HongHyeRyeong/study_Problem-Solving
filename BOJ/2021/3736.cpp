#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000;
const int INF = 1000000000;

int N;
// A[i], B[i]: 그룹의 i번 정점과 매칭된 상대편 그룹 정점 번호
// dist[i]: (A그룹의) i번 정점의 레벨(?)
// used: (A그룹의) 이 정점이 매칭에 속해 있는가?
int A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

void bfs()
{
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        // 매칭에 안 속한 A그룹의 정점만 레벨 0인 채로 시작
        if (!used[i]) {
            dist[i] = 0;
            Q.push(i);
        }
        else
            dist[i] = INF;
    }

    // A그룹 정점에 0, 1, 2, 3, ... 의 레벨을 매김
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

// 이분 매칭 알고리즘
bool dfs(int a)
{
    for (int b : adj[a]) {
        // 이분 매칭과 차이점: dist 배열에 대한 조건이 추가로 붙음
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

        // 호프크로프트 카프 알고리즘
        int answer = 0;
        while (1) {
            // 각 정점에 레벨을 매기고 시작
            bfs();

            // 이분 매칭 알고리즘을 이용해 증가 경로 찾기
            int flow = 0;
            for (int i = 0; i < N; i++)
                if (!used[i] && dfs(i))
                    flow++;
            answer += flow;

            // 더 이상 증가 경로를 못 찾으면 알고리즘 종료
            if (flow == 0)
                break;
        }

        cout << answer << '\n';
    }
}