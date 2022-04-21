#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 100000;
const int MAX_VAL = 1000000;

struct QueryNode {
    int i, j, index;
    int sqrtN;

    QueryNode() : QueryNode(0, 0, -1, 0) {}
    QueryNode(int i, int j, int index, int N) : i(i), j(j), index(index) { sqrtN = sqrt(N); }

    // (s/√N, e) 순으로 오름차순 정렬
    bool operator <(const QueryNode& O)const {
        if (i / sqrtN != O.i / sqrtN)
            return (i / sqrtN < O.i / sqrtN);
        return (j < O.j);
    }
};

int N, M, A[MAX]{};
int result[MAX]{};
QueryNode Q[MAX];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> M;

    // 쿼리를 입력받은 후 정렬
    for (int index = 0, i, j; index < M; ++index) {
        cin >> i >> j;
        Q[index] = QueryNode(i - 1, j, index, N);
    }
    sort(Q, Q + M);

    // 첫 번째에 위치한 쿼리의 결과는 손수 구함
    int dcnt = 0, cnt[MAX_VAL + 1]{};
    int i0 = Q[0].i, j0 = Q[0].j;
    for (int i = i0; i < j0; ++i)
        if (cnt[A[i]]++ == 0)
            ++dcnt;

    result[Q[0].index] = dcnt;

    // 다음 쿼리부터 바로 이전 쿼리의 결과를 사용해 계산해 나감
    for (int i = 1; i < M; ++i) {
        while (Q[i].i < i0) if (cnt[A[--i0]]++ == 0) ++dcnt;
        while (j0 < Q[i].j) if (cnt[A[j0++]]++ == 0) ++dcnt;
        while (Q[i].i > i0) if (--cnt[A[i0++]] == 0) --dcnt;
        while (j0 > Q[i].j) if (--cnt[A[--j0]] == 0) --dcnt;
        result[Q[i].index] = dcnt;
    }

    for (int i = 0; i < M; ++i)
        cout << result[i] << "\n";
}