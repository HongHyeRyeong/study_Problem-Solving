#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long sum = 0;
        for (int i = 0; i < gas.size(); ++i)
            sum += gas[i] - cost[i];
        if (sum < 0)
            return -1;

        int index = 0;
        sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                index = i + 1;
            }
        }
        return index;
    }
};