class Solution {
public://very greedy 
// zero will be shifted to the right jitne number of 0s hai string me 
//000110-> 4 zeros means zero will be shifted at 4th place 
// hence ans=111011 dry running we see we want to converge 2  zeros using 10->01
//hence vaha pr zero ayega jaha pr zero start hua+count of zero 
    string maximumBinaryString(string binary) {
        int n=binary.size();
        string ans(n,'1');
        int cnt=0;
        for(int i=0;i<n;i++){
            if(binary[i]=='0')cnt++;
        }
        for(int i=0;i<n;i++){
            if(binary[i]=='0')// got our 1st zero{

            {
                ans[cnt+i-1]='0';
                return ans;
            }
        }
        return ans;
    }
};