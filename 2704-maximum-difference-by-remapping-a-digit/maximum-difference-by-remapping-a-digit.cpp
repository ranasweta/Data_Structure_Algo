class Solution {
public:
    int minMaxDifference(int num) {
        string a=to_string(num);
        int l=0;
        if(a[0]=='9'){
            for(int i=0;i<a.size();i++){
                if(a[i]!='9'){
                    l=i;
                    break;
                }
            }
        }
        char o=a[l];
        for(int i=l;i<a.size();i++){
            if(a[i]==o){
                a[i]='9';
            }
           
        }
        int mx=stoi(a);
        a=to_string(num);
        l=0;
        if(a[0]=='0'){
            for(int i=0;i<a.size();i++){
                if(a[i]!='0'){
                    l=i;
                    break;
                }
            }
        }
        o=a[l];
        for (int i=l;i<a.size();i++){
            if(a[i]==o){
                a[i]='0';
            }
        }
        int mn=stoi(a);
        return mx-mn;
        
    }
};