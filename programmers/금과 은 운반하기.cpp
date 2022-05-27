#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
	long long answer = -1;
	long long start = 0, end = 10e5 * 4 * 10e9;
	answer = end;

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long gold = 0, silver = 0, goldSilver = 0;

		for (int i = 0; i < g.size(); i++)
		{
			long long move = mid / (t[i] * 2) + ((mid % (t[i] * 2) >= t[i]) ? 1 : 0);
			long long take = w[i] * move;

			gold += min((long long)g[i], take);
			silver += min((long long)s[i], take);
			goldSilver += min((long long)g[i] + s[i], take);
		}

		if (gold >= a && silver >= b && goldSilver >= a + b) {
			answer = min(answer, mid);
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	return answer;
}