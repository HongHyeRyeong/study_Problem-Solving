#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 500;
const int MAX_V = MAX_N + 2;
const int S = MAX_V - 2;
const int E = MAX_V - 1;
const int INF = 1000000000;

vector<int> adj[MAX_V];
int c[MAX_V][MAX_V], f[MAX_V][MAX_V];
int level[MAX_V], work[MAX_V];

// 레벨 그래프(level graph) 만들기
bool LevelGraph()
{
    fill(level, level + MAX_V, -1);
    level[S] = 0;

    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (int next : adj[curr]) {
            // 레벨값이 설정되지 않았고 간선에 여유 용량이 있을 때 이동
            if (level[next] == -1 && c[curr][next] - f[curr][next] > 0) {
                level[next] = level[curr] + 1; // next의 레벨은 curr의 레벨 + 1
                Q.push(next);
            }
        }
    }

    return level[E] != -1; // 싱크에 도달 가능하면 true
}

// 차단 유량(blocking flow) 구하기: curr에서 dest까지 최대 flow 유량을 보낼 수 있는지
int BlockingFlow(int curr, int dest, int flow)
{
    if (curr == dest)
        return flow;

    // 이미 쓸모없다고 판단한 간선은 다시 볼 필요가 없으므로 work 배열로 간선 인덱스를 저장
    for (int& i = work[curr]; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        // next 레벨이 curr 레벨 + 1이고 간선에 여유 용량이 있을 때 이동
        if (level[next] == level[curr] + 1 && c[curr][next] - f[curr][next] > 0) {
            // df: 경로상의 간선들 중 가장 작은 여유 용량
            int df = BlockingFlow(next, dest, min(c[curr][next] - f[curr][next], flow));            
            if (df > 0) { // 증가 경로가 있다면 df 유량을 흘리고 종료
                f[curr][next] += df;
                f[next][curr] -= df;
                return df;
            }
        }
    }

    return 0; // 증가 경로를 찾지 못함
}

int Dinic()
{
    int total = 0;

    while (LevelGraph()) { // 싱크에 도달할 수 없다면 종료      
        fill(work, work + MAX_V, 0);
        while (1) {
            int flow = BlockingFlow(S, E, INF);
            if (flow == 0)
                break; // 더 이상 차단 유량이 없다면 종료
            total += flow;
        }
    }

    return total;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int team;
        cin >> team;
        if (team == 1) {
            c[S][i] = INF;
            adj[S].push_back(i);
            adj[i].push_back(S);
        }
        else if (team == 2) {
            c[i][E] = INF;
            adj[i].push_back(E);
            adj[E].push_back(i);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
            if (i != j)
                adj[i].push_back(j);
        }
    }

    cout << Dinic() << '\n';

    // 각 진영에 속한 사람을 판단하기 위해 소스에서의 도달 가능성 판별
    bool visited[MAX_V]{ false };
    visited[S] = true;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (int next : adj[curr]) {
            // 여유 용량이 남아있는 간선만을 이용
            if (!visited[next] && c[curr][next] - f[curr][next] > 0) {
                visited[next] = true;
                Q.push(next);
            }
        }
    }

    // A진영에 속한 사람들: 소스에서 도달 가능
    for (int i = 0; i < N; i++)
        if (visited[i])
            cout << i + 1 << ' ';
    cout << '\n';
    // B진영에 속한 사람들: 소스에서 도달 불가능
    for (int i = 0; i < N; i++)
        if (!visited[i])
            cout << i + 1 << ' ';
    cout << '\n';
}