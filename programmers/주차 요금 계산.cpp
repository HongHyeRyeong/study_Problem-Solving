#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int ConvertTimeToInt(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int GetFee(vector<int> fees, vector<int> times)
{
    if (times.size() % 2 == 1)
        times.push_back(ConvertTimeToInt("23:59"));

    int totalTime = 0;
    for (int i = 0; i < times.size(); ++i)
        totalTime += times[i];

    return fees[1] + max(0, (int)ceil((float)(totalTime - fees[0]) / fees[2]) * fees[3]);
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    map<int, vector<int>> inout;
    for (int i = 0; i < records.size(); ++i) {
        string time = records[i].substr(0, 5), type = records[i].substr(11, 1);
        int car = stoi(records[i].substr(6, 4));

        inout[car].push_back(ConvertTimeToInt(time) * (type == "I" ? -1 : 1));
    }

    for (auto a : inout)
        answer.push_back(GetFee(fees, a.second));

    return answer;
}