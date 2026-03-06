class Solution {
public:
    bool checkOnesSegment(string s) {
        bool grp=false;//which means ones contigous is not present yet
        int i=0;
        while(s[i]=='1'){
            i++;
        }
        while(s[i]=='0'){
            i++;
        }
        return i==s.length();
    }
};