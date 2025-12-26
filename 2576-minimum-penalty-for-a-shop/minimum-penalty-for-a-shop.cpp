class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = 0;
        for(char c : customers) if(c == 'Y') totalY++;

        int penalty = totalY; // initially, if closed at 0
        int mn = penalty;
        int res = 0;

        int seenN = 0, seenY = 0;
        int n=customers.size();
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') seenY++;
            else seenN++;

            // penalty if closed after hour i+1
            int curr = seenN + (totalY - seenY);
            if(curr < mn) {
                mn = curr;
                res = i+1;
            }
        }
        return res;
    }
};