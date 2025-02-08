class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_all = 0;
    
        for (int num : nums)
            xor_all ^= num;
        
        long diff_bit = xor_all & -xor_all;
        int num1 = 0, num2 = 0;
        
        for (int num : nums) {
            if (num & diff_bit)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {num1, num2};        
    }
};
