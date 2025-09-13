class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> vowels={'a','e','i','o','u'};
        sort(begin(s),end(s));
        int v=(find(begin(vowels),end(vowels),s[0])!=vowels.end()?1:0);
        int c=!v;
        int mv=0;
        int mc=0;

        for(int i=0;i<s.length();i++){
            if(i>0 && s[i]==s[i-1]){
                if(find(begin(vowels),end(vowels),s[i])!=vowels.end()){
                    v++;
                }
                else{
                    c++;
                }
            }
            else{
                mv=max(v,mv);
                mc=max(c,mc);
                v=(find(begin(vowels),end(vowels),s[i])!=vowels.end()?1:0);
                c=!v;

            }
        }
        mv=max(v,mv);
        mc=max(c,mc);
        return mv+mc;
    }
};