#include <iostream>
#include <string>
using namespace std;


class Stack {
private:
	int index;
	int num[10001];

public:
	Stack() {
		index = -1;

		for (int i = 0; i < 10001; ++i)
			num[i] = 0;
	}

	void Push(int x) {
		num[++index] = x;
	}

	int Pop() {
		if (index == -1)
			return -1;
		return num[index--];
	}

	int Size() {
		return index + 1;
	}

	bool Empty() {
		return !Size();
	}

	int Top() {
		if (index == -1)
			return -1;
		return num[index];
	}
};

Stack stack;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	while (N--) {
		string order;
		cin >> order;

		if (order == "push") {
			int x;
			cin >> x;

			stack.Push(x);
		}
		else if (order == "pop") {
			cout << stack.Pop() << "\n";
		}
		else if (order == "size") {
			cout << stack.Size() << "\n";
		}
		else if (order == "empty") {
			cout << stack.Empty() << "\n";
		}
		else if (order == "top") {
			cout << stack.Top() << "\n";
		}
	}
}