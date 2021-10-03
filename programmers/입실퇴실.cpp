#include <string>
#include <vector>
using namespace std;

bool isMeet[1001][1001];

vector<int> solution(vector<int> enter, vector<int> leave) {
    int size = enter.size();
    vector<int> answer(size, 0);

    for (int i = 0; i < size; ++i) { // leave
        int meetCount = 0;
        for (int j = 0; j < size; ++j) { // enter
            if (leave[i] == enter[j])
                break;
            if (isMeet[enter[j]][0] == false)
                meetCount++;
        }

        for (int j = 0; j < size; ++j) { // enter
            if (meetCount == 0)
                break;

            if (isMeet[enter[j]][0] == false) {
                answer[enter[j] - 1] += meetCount;

                // 중복된 경우 제거
                for (int k = 0; k < size; ++k) { // enter
                    if (enter[j] == enter[k] || isMeet[enter[k]][0])
                    {
                        if (leave[i] == enter[k])
                            break;
                        continue;
                    }

                    if (isMeet[enter[j]][enter[k]])
                        answer[enter[j] - 1]--;
                    isMeet[enter[j]][enter[k]] = true;

                    if (leave[i] == enter[k])
                        break;
                }
            }

            if (leave[i] == enter[j])
                break;
        }

        isMeet[leave[i]][0] = true;
    }

    return answer;
}