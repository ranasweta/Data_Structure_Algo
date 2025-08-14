class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        
        for (int n : nums) {
            if (n <= first) {
                first = n;  // smallest so far
            } 
            else if (n <= second) {
                second = n; // second smallest so far
            } 
            else {
                return true; // found n > second > first
            }
        }
        return false;
    }
};
