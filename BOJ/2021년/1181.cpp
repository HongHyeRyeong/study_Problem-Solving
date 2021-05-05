#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<string> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(), [](string s1, string s2) {
		if (s1.size() == s2.size())
			return s1 < s2;
		return s1.size() < s2.size();
		});

	v.erase(unique(v.begin(), v.end()), v.end());

	for (string s : v)
		cout << s << "\n";
}