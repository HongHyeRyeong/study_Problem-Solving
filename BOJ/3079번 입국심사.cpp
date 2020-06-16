#include <iostream>
#include <algorithm>
using namespace std;

long long t[100000];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> t[i];

    long long start = 1, end = *max_element(t, t + N) * M, mid;
    while (start <= end) {
        mid = (start + end) / 2;

        long long num = 0;
        for (int i = 0; i < N; ++i)
            num += mid / t[i];

        if (num >= M)
            end = mid - 1;
        else
            start = mid + 1;
    }
    cout << start;
}