class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if(p.length()<8) return false;
        bool l=0,u=0,d=0,s=0;
        string punct="!@#$%^&*()-+";
        for(int i=0;i<p.length();i++){
            if(i>0 && p[i]==p[i-1]){
                return false;
            }
            else if(p[i]<='z' && p[i]>='a') l=1;
            else if(p[i]<='Z' && p[i]>='A') u=1;
            else if(p[i]<='9' && p[i]>='0') d=1;
            else if(punct.find(p[i])!=string::npos) s=1;

        }
        return l&u&d&s;
    }
};