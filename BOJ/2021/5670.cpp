#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie
{
	Trie* child[26];
	bool finish;
	int childCount;

	Trie() :finish(false), childCount(0)
	{
		for (int i = 0; i < 26; ++i)
			child[i] = NULL;
	}

	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (child[i])
				delete child[i];
	}

	void insert(const char* key)
	{
		if (*key == 0)
			finish = true;
		else
		{
			int nextKey = *key - 'a';
			if (child[nextKey] == NULL) {
				child[nextKey] = new Trie();
				childCount++;
			}
			child[nextKey]->insert(key + 1);
		}
	}

	int find(const char* str, bool first = false)
	{
		if (*str == 0)
			return 0;
		if (first || finish || childCount > 1)
			return 1 + child[*str - 'a']->find(str + 1);
		return child[*str - 'a']->find(str + 1);
	}
};

int main()
{
	int n;
	while (cin >> n) {
		vector<string> str(n);
		Trie* trie = new Trie();
		for (int i = 0; i < n; ++i) {
			cin >> str[i];
			trie->insert(str[i].c_str());
		}

		int answer = 0;
		for (int i = 0; i < n; ++i)
			answer += trie->find(str[i].c_str(), true);
		printf("%.2f\n", (double)answer / n);

		delete trie;
	}
}