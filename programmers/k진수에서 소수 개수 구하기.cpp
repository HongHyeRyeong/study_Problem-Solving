#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool IsPrime(long long n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int solution(int n, int k)
{
    string nums = "";
    while (n > 0) {
        nums = to_string(n % k) + nums;
        n /= k;
    }

    int answer = 0;
    string num = "";
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != '0')
            num += nums[i];
        if (nums[i] == '0' || i == nums.size() - 1) {
            if (!num.empty() && IsPrime(stol(num)))
                answer++;
            num = "";
        }
    }
    return answer;
}