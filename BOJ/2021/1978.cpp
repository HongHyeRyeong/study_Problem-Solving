#include <iostream>
using namespace std;

int main()
{
	int answer = 0;

	bool nums[1001]{ 1,1 };
	for (int i = 2; i * i <= 1000; ++i)
		if (!nums[i])
			for (int j = i * i; j <= 1000; j += i)
				nums[j] = true;

	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;

		if (!nums[num])
			answer++;
	}

	cout << answer;
}