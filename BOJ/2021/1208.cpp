#include<iostream>
#include<map>
using namespace std;

int N, S;
int arr[41];

long long answer;
map<int, int> subsum;

void MeetInTheMiddle(int start, int end, int sum)
{
    if (start == end) {
        if (end == N)
            answer += subsum[S - sum]; // 2. 오른쪽 합(=S-왼쪽 합) 개수 구하기
        else
            subsum[sum]++; // 1. 왼쪽 합 개수 구하기
        return;
    }

    MeetInTheMiddle(start + 1, end, sum + arr[start]);
    MeetInTheMiddle(start + 1, end, sum);
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    MeetInTheMiddle(0, N / 2, 0);
    MeetInTheMiddle(N / 2, N, 0);

    // 아무것도 뽑지 않았을 때 빼주기
    answer += S == 0 ? -1 : 0;
    cout << answer;
}