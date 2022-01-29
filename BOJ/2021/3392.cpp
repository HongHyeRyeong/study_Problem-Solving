#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 30002

struct Point {
    int x, y1, y2;
    bool start;
};

vector<Point> points;
int segtree[SIZE * 4];
int cnt[SIZE * 4];

void update(int node, int start, int end, int left, int right, int val) 
{
    if (start > right || end < left) 
        return;

    if (left <= start && end <= right) {
        cnt[node] += val;
    }
    else {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right, val);
        update(node * 2 + 1, mid + 1, end, left, right, val);
    }

    if (cnt[node])
        segtree[node] = end - start + 1;
    else {
        if (start == end)
            segtree[node] = 0;
        else
            segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point temp;
        temp.y1 = y1 + 1, temp.y2 = y2 + 1;
        temp.x = x1, temp.start = true;
        points.push_back(temp);
        temp.x = x2, temp.start = false;
        points.push_back(temp);
    }

    sort(points.begin(), points.end(), [](Point& a, Point& b) {
        return a.x < b.x;        
        });

    int answer = 0;
    for (int i = 0; i < points.size(); i++) {
        if (i > 0)
            answer += (points[i].x - points[i - 1].x) * segtree[1];
        update(1, 1, SIZE, points[i].y1, points[i].y2 - 1, points[i].start ? 1 : -1);
    }
    cout << answer;
}