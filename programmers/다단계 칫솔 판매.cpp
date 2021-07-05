#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer(enroll.size(), 0);

    unordered_map<string, string> group;
    unordered_map<string, int> sellerIndex;
    for (int i = 0; i < enroll.size(); ++i) {
        group[enroll[i]] = referral[i];
        sellerIndex[enroll[i]] = i;
    }

    for (int i = 0; i < seller.size(); i++) {
        int money = amount[i] * 100;
        while (seller[i] != "-" && money > 0) {
            answer[sellerIndex[seller[i]]] += money - money / 10;
            money /= 10;
            seller[i] = group[seller[i]];
        }
    }

    return answer;
}