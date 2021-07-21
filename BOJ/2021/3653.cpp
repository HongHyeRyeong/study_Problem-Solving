#include <iostream>
#include <vector>
using namespace std;

int N, M;
int totalSize;
vector<long long> tree, collection;

long long init(int node, int start, int end)
{
    if (start == end) {
        if (start >= M) {
            collection[start - M] = start;
            tree[node] = 1;
        }
        return tree[node];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long query(int node, int start, int end, int nodeLeft, int nodeRight)
{
    if (end < nodeLeft || nodeRight < start)
        return 0;
    if (start <= nodeLeft && nodeRight <= end)
        return tree[node];

    int mid = (nodeLeft + nodeRight) / 2;
    return query(node * 2, start, end, nodeLeft, mid) + query(node * 2 + 1, start, end, mid + 1, nodeRight);
}

long long update(int idx, int node, int val, int nodeLeft, int nodeRight)
{
    if (idx < nodeLeft || nodeRight < idx)
        return tree[node];
    if (nodeLeft == nodeRight)
        return tree[node] = val;

    int mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, node * 2, val, nodeLeft, mid) + update(idx, node * 2 + 1, val, mid + 1, nodeRight);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        tree.clear();
        collection.clear();

        cin >> N >> M;

        totalSize = N + M;
        tree.resize(4 * totalSize, 0);
        collection.resize(N);

        init(1, 0, totalSize - 1);

        int idx = M - 1; // 빈공간
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;

            cout << query(1, 0, collection[num - 1] - 1, 0, totalSize - 1) << " ";

            update(collection[num - 1], 1, 0, 0, totalSize - 1); // 해당 디비디를 꺼내고
            collection[num - 1] = idx; // 디비디의 위치를 바꾼다
            update(collection[num - 1], 1, 1, 0, totalSize - 1); // 누적합 업데이트
            idx--;
        }

        cout << "\n";
    }
}