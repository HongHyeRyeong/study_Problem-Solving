#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int HASH_SIZE = 100003;

int Mod(long long x)
{
    if (x >= 0)
        return x % HASH_SIZE;
    return ((-x / HASH_SIZE + 1) * HASH_SIZE + x) % HASH_SIZE;
}

int main()
{
    int L;
    string str;
    cin >> L >> str;

    int start = 0, end = L;
    while (start + 1 < end) {
        vector <int> hash[HASH_SIZE];
        int mid = (start + end) / 2, h = 0, po = 1;
        bool found = false;

        // �ؽð�(h) �����
        for (int i = 0; i <= L - mid; i++) {
            if (i == 0) {
                for (int j = 0; j < mid; j++) {
                    h = Mod(h + 1LL * str[mid - j - 1] * po);
                    if (j < mid - 1)
                        po = Mod(po * 2);
                }
            }
            else
                h = Mod(2 * (h - 1LL * str[i - 1] * po) + str[i + mid - 1]);

            if (!hash[h].empty()) {
                // �ؽ� �浹�� �� str�� [i, i+m-1]�� [p, p+mid-1]�� ���ڿ��� ������ ��
                for (int p : hash[h]) {
                    for (int j = 0; j < mid; j++) {
                        if (str[i + j] != str[p + j])
                            break;
                        if (j == mid - 1)
                            found = true;
                    }
                }
            }

            if (!found)
                hash[h].push_back(i);
        }

        if (found)
            start = mid; // ã������ �� ���� ���� Ž��
        else
            end = mid; // ������ �� ���� ���� Ž��
    }

    cout << start;
}