class Solution {
public:
    bool hasSameDigits(string s) {
        string temp="";
        while(s.length()>2){
            temp="";
            for(int i=0;i<s.length()-1;i++){
                temp.push_back((s[i]-'0'+s[i+1]-'0')%10+'0');
            }
            s=temp;
            
        }
        cout<<s<<" ";
        return temp[0]==temp[1];
    }
};