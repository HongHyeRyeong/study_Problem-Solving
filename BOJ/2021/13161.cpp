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

// ���� �׷���(level graph) �����
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
            // �������� �������� �ʾҰ� ������ ���� �뷮�� ���� �� �̵�
            if (level[next] == -1 && c[curr][next] - f[curr][next] > 0) {
                level[next] = level[curr] + 1; // next�� ������ curr�� ���� + 1
                Q.push(next);
            }
        }
    }

    return level[E] != -1; // ��ũ�� ���� �����ϸ� true
}

// ���� ����(blocking flow) ���ϱ�: curr���� dest���� �ִ� flow ������ ���� �� �ִ���
int BlockingFlow(int curr, int dest, int flow)
{
    if (curr == dest)
        return flow;

    // �̹� ������ٰ� �Ǵ��� ������ �ٽ� �� �ʿ䰡 �����Ƿ� work �迭�� ���� �ε����� ����
    for (int& i = work[curr]; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        // next ������ curr ���� + 1�̰� ������ ���� �뷮�� ���� �� �̵�
        if (level[next] == level[curr] + 1 && c[curr][next] - f[curr][next] > 0) {
            // df: ��λ��� ������ �� ���� ���� ���� �뷮
            int df = BlockingFlow(next, dest, min(c[curr][next] - f[curr][next], flow));            
            if (df > 0) { // ���� ��ΰ� �ִٸ� df ������ �긮�� ����
                f[curr][next] += df;
                f[next][curr] -= df;
                return df;
            }
        }
    }

    return 0; // ���� ��θ� ã�� ����
}

int Dinic()
{
    int total = 0;

    while (LevelGraph()) { // ��ũ�� ������ �� ���ٸ� ����      
        fill(work, work + MAX_V, 0);
        while (1) {
            int flow = BlockingFlow(S, E, INF);
            if (flow == 0)
                break; // �� �̻� ���� ������ ���ٸ� ����
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

    // �� ������ ���� ����� �Ǵ��ϱ� ���� �ҽ������� ���� ���ɼ� �Ǻ�
    bool visited[MAX_V]{ false };
    visited[S] = true;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (int next : adj[curr]) {
            // ���� �뷮�� �����ִ� �������� �̿�
            if (!visited[next] && c[curr][next] - f[curr][next] > 0) {
                visited[next] = true;
                Q.push(next);
            }
        }
    }

    // A������ ���� �����: �ҽ����� ���� ����
    for (int i = 0; i < N; i++)
        if (visited[i])
            cout << i + 1 << ' ';
    cout << '\n';
    // B������ ���� �����: �ҽ����� ���� �Ұ���
    for (int i = 0; i < N; i++)
        if (!visited[i])
            cout << i + 1 << ' ';
    cout << '\n';
}