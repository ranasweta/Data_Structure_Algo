class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, zeros = 0;
        int result = 0;

        for (int k = 0; k < 32; k++) {
            int temp = (1 << k);
            ones = 0;
            zeros = 0;
            for (int& num : nums) {
                if ((num & temp) != 0) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            if((ones%3)==1){
                result=result|temp;
            }
        }
        return result;
    }
};