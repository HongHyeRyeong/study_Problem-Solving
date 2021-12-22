#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string T, string P)
{
    vector<int> answer;
    int n = T.size(), m = P.size();

    // pi[i] 배열 구현
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }

    // kmp 함수 구현
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j]) {
            if (j == m - 1) {
                answer.push_back(i - m + 2);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }

    return answer;
}

int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int N;
    string meat, roulette;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        meat += c;
    }
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        roulette += c;
    }

    roulette += roulette;
    roulette.pop_back();

    int answer = kmp(roulette, meat).size();
    int gcdNum = gcd(N, answer);
    cout << answer / gcdNum << "/" << N / gcdNum;
}