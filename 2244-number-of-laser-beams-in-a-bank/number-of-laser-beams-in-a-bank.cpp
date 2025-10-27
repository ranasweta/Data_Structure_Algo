class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int initial=0;
        int ans=0;
        for(string b:bank){
            int a = 0;

    for (char ch : b) {
        if (ch == '1') {
            a++;
        }
    }
            if(a!=0){
                ans+=a*initial;
                initial=a;
            }
        }
        return ans;
    }
};