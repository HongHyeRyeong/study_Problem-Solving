#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    map<string, int> idIndex;
    for (int i = 0; i < id_list.size(); ++i)
        idIndex[id_list[i]] = i;

    map<string, vector<string>> reportId;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (int i = 0; i < report.size(); ++i) {
        int splitIndex = report[i].find(' ');
        string id1 = report[i].substr(0, splitIndex), id2 = report[i].substr(splitIndex + 1);
        reportId[id2].push_back(id1);
    }

    vector<int> answer(id_list.size(), 0);
    for (auto a : reportId) {
        if (a.second.size() >= k)
            for (int i = 0; i < a.second.size(); ++i)
                answer[idIndex[a.second[i]]]++;
    }
    return answer;
}