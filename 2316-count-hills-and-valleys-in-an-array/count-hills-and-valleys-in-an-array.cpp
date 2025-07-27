class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> temp;
        // Remove consecutive duplicates
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
            }
        }

        int count = 0;
        for (int i = 1; i < temp.size() - 1; ++i) {
            if ((temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) || 
                (temp[i] < temp[i - 1] && temp[i] < temp[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
