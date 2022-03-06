#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_STATE 17

struct Point {
    int index, state, ship, wolf;
};

vector<int> graph[MAX_STATE];
bool visited[MAX_STATE][1 << MAX_STATE];

int solution(vector<int> info, vector<vector<int>> edges)
{
    int answer = 0;

    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    queue<Point> q;
    q.push({ 0,1,1,0 });
    visited[0][1] = true;
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        answer = max(answer, curr.ship);

        for (int next : graph[curr.index]) {
            int nstate = curr.state | (1 << next);
            if (visited[next][nstate])
                continue;

            int ns = 0, nw = 0;
            if (!(curr.state & (1 << next))) {
                if (info[next]) { // ´Á´ë
                    if (curr.ship <= curr.wolf + 1)
                        continue;
                    nw = 1;
                }
                else { // ¾ç
                    ns = 1;
                }
            }

            visited[next][nstate] = true;
            q.push({ next,nstate,curr.ship + ns,curr.wolf + nw });
        }
    }

    return answer;
}