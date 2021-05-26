#include <iostream>
#include <vector>
using namespace std;

bool prime[4000001] = { true, true };

int main()
{
	for (int i = 2; i * i <= 4000000; ++i)
		if (!prime[i])
			for (int j = i * i; j <= 4000000; j += i)
				prime[j] = true;

	vector<int> primeNum;
	for (int i = 0; i <= 4000000; ++i)
		if (!prime[i])
			primeNum.push_back(i);

	int N;
	cin >> N;

	int answer = 0, sum = 0;
	int start = 0, end = 0;
	while (true) {
		if (sum >= N)
			sum -= primeNum[start++];
		else if (end == primeNum.size())
			break;
		else
			sum += primeNum[end++];

		if (sum == N)
			answer++;
	}

	cout << answer;
}