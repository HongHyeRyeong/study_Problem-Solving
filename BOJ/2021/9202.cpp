#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Trie
{
	Trie* next[26];
	bool finish;

	Trie() :finish(false)
	{
		for (int i = 0; i < 26; ++i)
			next[i] = NULL;
	}

	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key)
	{
		if (*key == 0) {
			finish = true;
			return;
		}

		int curr = *key - 'A';
		if (next[curr] == NULL)
			next[curr] = new Trie();
		next[curr]->insert(key + 1);
	}

	int find(const char* key)
	{
		if (*key == 0)
			return finish ? 2 : 1;

		int curr = *key - 'A';
		if (next[curr] != NULL)
			return next[curr]->find(key + 1);
		return 0;
	}
};

Trie* trie;

const int SIZE = 4;
char board[SIZE][SIZE];
bool checked[SIZE][SIZE];
vector<string> findWords;
vector<int> points{ 0,0,0,1,1,2,3,5,11 };

void dfs(int x, int y, string word)
{
	if (0 > x || x >= SIZE || 0 > y || y >= SIZE || checked[y][x])
		return;

	word += board[y][x];
	int find = trie->find(word.c_str());
	if (find != 0) // 일치하는 글자 없음
	{
		if (find == 2)
			findWords.push_back(word);

		checked[y][x] = true;
		dfs(x + 1, y, word);
		dfs(x - 1, y, word);
		dfs(x, y + 1, word);
		dfs(x, y - 1, word);
		dfs(x + 1, y + 1, word);
		dfs(x + 1, y - 1, word);
		dfs(x - 1, y + 1, word);
		dfs(x - 1, y - 1, word);
		checked[y][x] = false;
	}
}

int main()
{
	trie = new Trie();
	int w, b;
	string s;

	scanf("%d", &w);
	getline(cin, s);

	for (int i = 0; i < w; ++i) {
		getline(cin, s);
		trie->insert(s.c_str());
	}
	getline(cin, s);

	scanf("%d", &b);
	while (b--) {
		getline(cin, s);
		for (int i = 0; i < 4; ++i) {
			getline(cin, s);
			for (int j = 0; j < 4; ++j)
				board[i][j] = s[j];
		}

		findWords.clear();
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j) {
				for (int k = 0; k < SIZE; ++k)
					for (int l = 0; l < SIZE; ++l)
						checked[k][l] = false;
				dfs(i, j, "");
			}

		sort(findWords.begin(), findWords.end(), [](string& a, string& b) {
			if (a.size() == b.size())
				return a < b;
			return a.size() > b.size();
			});
		findWords.erase(unique(findWords.begin(), findWords.end()), findWords.end());

		int score = 0, maxWord;
		for (int i = 0; i < findWords.size(); ++i)
			score += points[findWords[i].size()];

		cout << score << " " << (findWords.empty() ? "" : findWords[0]) << " " << findWords.size() << endl;
	}

	delete trie;
}