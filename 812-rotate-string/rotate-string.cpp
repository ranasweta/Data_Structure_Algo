class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.length();
        s=s+s;
        int n=goal.length();
        if(m!=n){
            return false;
        }
        for(int i=0;i<goal.size();i++){
            if(s.substr(i,n)==goal){
                return true;
            }
        }
        return false;
    }
};