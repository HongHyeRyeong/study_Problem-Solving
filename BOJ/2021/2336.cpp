#include <iostream>
#include <algorithm>
using namespace std;

int scores[3][500001];
pair<int, int> firstTest[500001];

struct segment {
    int* tree;

    segment(int n) {
        tree = new int[n * 4 + 1];
        for (int i = 1; i <= n * 4; i++)
            tree[i] = 1e9;
    }

    int update(int l, int r, int dst, int val, int node) {
        if (r < dst || l > dst)
            return tree[node];
        if (l == r)
            return tree[node] = val;

        int mid = l + r >> 1;
        int a = update(l, mid, dst, val, node * 2);
        int b = update(mid + 1, r, dst, val, node * 2 + 1);
        return tree[node] = min(a, b);
    }

    int minValue(int l, int r, int s, int e, int node) {
        if (l > e || r < s)
            return 1e9;
        if (l >= s && r <= e)
            return tree[node];

        int mid = l + r >> 1;
        int a = minValue(l, mid, s, e, node * 2);
        int b = minValue(mid + 1, r, s, e, node * 2 + 1);
        return min(a, b);
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            scores[i][num] = j;
        }
    }
    
    // 첫번째 시험 등수대로 정렬
    for (int i = 1; i <= n; i++)
        firstTest[i] = { scores[0][i], i };
    sort(firstTest + 1, firstTest + n + 1);

    int ans = 0;
    segment tree(500001);
    for (int i = 1; i <= n; i++) {
        int index = firstTest[i].second;

        // 최솟값이 현재 업데이트 중인 학생의 세번째 시험 등수보다 크다면
        if (tree.minValue(1, n, 1, scores[1][index], 1) > scores[2][index])
            ans++;

        tree.update(1, n, scores[1][index], scores[2][index], 1);
    }
    cout << ans;
}