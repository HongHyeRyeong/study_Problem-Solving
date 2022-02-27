#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 1 << 18;

struct MergeSortTree {
    vector<int> arr[SIZE];

    void construct()
    {
        for (int i = SIZE / 2 - 1; i > 0; --i) {
            vector<int>& c = arr[i], & l = arr[i * 2], & r = arr[i * 2 + 1];
            arr[i].resize(l.size() + r.size());

            for (int j = 0, p = 0, q = 0; j < c.size(); ++j)
                c[j] = (q == r.size() || (p < l.size() && l[p] < r[q])) ? l[p++] : r[q++];
        }
    }

    int greater(int left, int right, int value, int node = 1, int start = 0, int end = SIZE / 2)
    {
        if (end <= left || right <= start)
            return 0;
        if (left <= start && end <= right)
            return arr[node].end() - upper_bound(arr[node].begin(), arr[node].end(), value); // value 보다 큰 개수

        int mid = (start + end) / 2;
        return greater(left, right, value, node * 2, start, mid) + greater(left, right, value, node * 2 + 1, mid, end);
    }
}mst;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        mst.arr[SIZE / 2 + i].push_back(a);
    }

    mst.construct();

    int M, L = 0;
    cin >> M;
    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;
        L = mst.greater((i ^ L) - 1, j ^ L, k ^ L);
        cout << L << '\n';
    }
}