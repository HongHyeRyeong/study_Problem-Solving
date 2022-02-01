#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> pays(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> pays[i];

	stack<int> st;
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		while (!st.empty() && pays[i] < pays[st.top()]) {
			int t = st.top();
			st.pop();

			int width = i - (st.empty() ? 0 : st.top() + 1);
			ans = max(ans, (long long)pays[t] * width);
		}
		st.push(i);
	}
	cout << ans;
}