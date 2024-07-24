#include <string>
#include <iostream>
using namespace std;

class Trie
{
public:
	Trie* next[26];
	bool finish;

	Trie()
	{
		for (int i = 0; i < 26; ++i)
			next[i] = NULL;
		finish = false;
	}

	void insert(string word)
	{
		if (word == "") {
			finish = true;
			return;
		}

		int curr = word[0] - 'a';
		if (next[curr] == NULL)
			next[curr] = new Trie();
		next[curr]->insert(word.erase(0, 1));
	}

	bool search(string word)
	{
		if (word == "")
			return finish;

		int curr = word[0] - 'a';
		if (next[curr] != NULL)
			return next[curr]->search(word.erase(0, 1));
		return false;
	}

	bool startsWith(string prefix) 
	{
		if (prefix == "")
			return true;

		int curr = prefix[0] - 'a';
		if (next[curr] != NULL)
			return next[curr]->startsWith(prefix.erase(0, 1));

		return false;
	}
};
