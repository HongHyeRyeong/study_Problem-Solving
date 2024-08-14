#include <string>
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

		if (word[0] == '.')
		{
			string newWord = word.erase(0, 1);
			for (int i = 0; i < 26; ++i)
				if (next[i] != NULL && next[i]->search(newWord))
					return true;
		}
		else
		{
			int curr = word[0] - 'a';
			if (next[curr] != NULL)
				return next[curr]->search(word.erase(0, 1));
		}

		return false;
	}
};

class WordDictionary {
public:
	Trie* obj;

    WordDictionary() {
		obj = new Trie();
    }

    void addWord(string word) {
		obj->insert(word);
    }

    bool search(string word) {
		return obj->search(word);
    }
};
