#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 1 << 21;

struct SegTree {
    int treeStart;
    long long tree[SIZE], lazy[SIZE];

    SegTree() 
    {
        treeStart = SIZE / 2;
        fill(tree, tree + SIZE, 0);
        fill(lazy, lazy + SIZE, 0);
    }

    void init()
    {
        for (int i = treeStart - 1; i > 0; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    // 구간([start, end)) node의 lazy 값을 propagate
    void propagate(int node, int start, int end) 
    {
        if (lazy[node] != 0) {
            // 리프 노드가 아니면 자식들에게 lazy 미룸
            if (node < treeStart) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }

            tree[node] += lazy[node] * (end - start);
            lazy[node] = 0;
        }
    }

    // 구간([left, right))에 value를 더하라
    void update(int node, int start, int end, int left, int right, int value)
    {
        propagate(node, start, end);

        if (left >= end || right <= start)
            return;
        if (left <= start && end <= right) {
            lazy[node] += value;
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right, value);
        update(node * 2 + 1, mid, end, left, right, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // 구간([left, right))의 합을 구하라
    long long sum(int node, int start, int end, int left, int right)
    {
        propagate(node, start, end);

        if (left >= end || right <= start)
            return 0;
        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid, end, left, right);
    }
} seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        cin >> seg.tree[seg.treeStart + i];
    seg.init();

    for (int i = 0, a, b, c, d; i < M + K; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            seg.update(1, 0, seg.treeStart, b - 1, c, d);
        }
        else {
            cin >> b >> c;
            cout << seg.sum(1, 0, seg.treeStart, b - 1, c) << '\n';
        }
    }
}