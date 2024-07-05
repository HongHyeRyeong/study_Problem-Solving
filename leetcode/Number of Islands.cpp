#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	bool checked[301][301]{};

	void DFS(vector<vector<char>>& grid, int y, int x)
	{
		if (0 > y || y >= grid.size() || 0 > x || x >= grid[0].size())
			return;
		if (grid[y][x] == '0' || checked[y][x] == true)
			return;
		checked[y][x] = true;

		DFS(grid, y + 1, x);
		DFS(grid, y - 1, x);
		DFS(grid, y, x + 1);
		DFS(grid, y, x - 1);
	}

	int numIslands(vector<vector<char>>& grid) {
		int answer = 0;

		for (int y = 0; y < grid.size(); y++)
			for (int x = 0; x < grid[0].size(); x++)
				if (grid[y][x] == '1' && checked[y][x] == false) {
					answer++;
					DFS(grid, y, x);
				}

		return answer;
	}
};
