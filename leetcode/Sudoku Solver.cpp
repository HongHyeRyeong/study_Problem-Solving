#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<unordered_set<int>> rows;
	vector<unordered_set<int>> cols;
	vector<unordered_set<int>> boxes;

	void solveSudoku(vector<vector<char>>& board)
	{
		rows.resize(9);
		cols.resize(9);
		boxes.resize(9);

		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (board[i][j] != '.')
					insert(i, j, board[i][j] - '0');

		fill(board, 0, 0);
	}

	bool fill(vector<vector<char>>& board, int i, int j)
	{
		if (i == 8 && j == 9)
			return true;
		if (j == 9) {
			i++;
			j = 0;
		}

		if (board[i][j] == '.') {
			for (int value = 1; value < 10; value++) {
				if (isValid(i, j, value)) {
					board[i][j] = value + '0';
					if (fill(board, i, j + 1))
						return true;
					board[i][j] = '.';
					erase(i, j, value);
				}
			}
			return false;
		}

		return fill(board, i, j + 1);
	}

	bool isValid(int i, int j, int value)
	{
		if (rows[i].find(value) == rows[i].end() && 
			cols[j].find(value) == cols[j].end() && 
			boxes[(i / 3) * 3 + (j / 3)].find(value) == boxes[(i / 3) * 3 + (j / 3)].end())
		{
			insert(i, j, value);
			return true;
		}
		return false;
	}

	void insert(int i, int j, int value)
	{
		rows[i].insert(value);
		cols[j].insert(value);
		boxes[(i / 3) * 3 + (j / 3)].insert(value);
	}

	void erase(int i, int j, int value)
	{
		rows[i].erase(value);
		cols[j].erase(value);
		boxes[(i / 3) * 3 + (j / 3)].erase(value);
	}
};