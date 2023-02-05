#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int size1 = num1.size(), size2 = num2.size();
        vector<int> v(size1 + size2, 0);

        for (int i = 0; i < size1; i++) {
            int value = 0;
            int n1 = (int)(num1[size1 - i - 1] - '0');

            for (int j = 0; j < size2; j++) {
                int n2 = (num2[size2 - j - 1] - '0');

                int sum = n1 * n2 + v[i + j] + value;
                value = sum / 10;
                v[i + j] = sum % 10;
            }

            if (value > 0)
                v[i + size2] += value;
        }

        int start = size1 + size2 - 1;
        while (v[start] == 0) 
            start--;
        if (start == -1) 
            return "0";

        string s = "";
        for (int i = start; i >= 0; i--)
            s += (char)(v[i] + '0');
        return s;
    }
};