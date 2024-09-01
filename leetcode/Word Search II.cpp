#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Trie
{
public:
	Trie* next[26] { NULL };
	bool finish = false;

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

	~Trie()
	{
		for (auto next : next)
			if (next != nullptr)
				delete(next);
	}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); ++i)
            trie->insert(words[i]);

        vector<string> answer;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, trie, "", answer);

		delete(trie);
        return answer;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, Trie* trie, string word, vector<string>& answer) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (board[i][j] == '0')
            return;

        trie = trie->next[board[i][j] - 'a'];
        if (trie == NULL)
            return;
        
        word += board[i][j];        
        if (trie->finish && IsContain(word, answer) == false)
            answer.push_back(word);

        char temp = board[i][j];
        board[i][j] = '0'; 
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int x = 0; x < 4; x++)
                dfs(board, i + dx[x], j + dy[x], trie, word, answer);
        
        board[i][j] = temp; 
    }

    bool IsContain(string word, vector<string>& answer)
    {
        for (int i = 0; i < answer.size(); ++i)
            if (answer[i] == word)
                return true;
        return false;
    }
};
