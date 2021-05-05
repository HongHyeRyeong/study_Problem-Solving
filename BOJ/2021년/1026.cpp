#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int A[50], B[50];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> B[i];

	sort(A, A + N);
	sort(B, B + N);

	int S = 0;
	for (int i = 0; i < N; ++i)
		S += A[i] * B[N - i - 1];

	cout << S;
}