class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(begin(digits),end(digits));
        int carry=0;
        for(int i=0;i<digits.size();i++){
            if(i==0||carry){
                digits[i]+=1;
                carry=digits[i]/10;
                digits[i]=digits[i]%10;
            }
            
        }
        if(carry){
            digits.push_back(carry);
        }
        reverse(begin(digits),end(digits));
        return digits;
    }
};