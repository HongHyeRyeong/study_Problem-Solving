#include <vector>
using namespace std;

const int SIZE = 11;

vector<int> answer, points, apPoints;
int maxScoreGap = 0;

int getScoreGap()
{
	int apScore = 0, score = 0;
	for (int i = 0; i < SIZE; i++) {
		if (apPoints[i] != 0 || points[i] != 0)
			apPoints[i] < points[i] ? score += 10 - i : apScore += 10 - i;
	}
	return score - apScore;
}

void dfs(int t, int n)
{
	if (t == n) {
		int scoreGap = getScoreGap();
		if (scoreGap != 0 && maxScoreGap <= scoreGap) {
			maxScoreGap = scoreGap;
			answer.resize(SIZE);
			for (int i = 0; i < SIZE; ++i)
				answer[i] = points[i];
		}
		return;
	}

	for (int i = 0; i < SIZE && points[i] <= apPoints[i]; i++) {
		points[i]++;
		dfs(t + 1, n);
		points[i]--;
	}
}

vector<int> solution(int n, vector<int> info)
{
	answer.push_back(-1);
	points.resize(SIZE);
	apPoints = info;

	dfs(0, n);

	return answer;
}