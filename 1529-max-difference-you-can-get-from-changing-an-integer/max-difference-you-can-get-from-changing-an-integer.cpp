class Solution {
public:
typedef long long ll;
    int maxDiff(int nums) {
        string s=to_string(nums);
        int n=s.length();
        if(n==1){
            return 8;
        }
        int l=0;
        if(s[0]=='9'){
            int i=0;
            while(s[i]=='9'){
                i++;
            }
            l=i;
        }
        int a=0;
        char k=s[l];
        for(int i=l;i<n;i++){
            if(s[i]==k){
                s[i]='9';
            }
        }
        a=stoi(s);
        cout<<a<<" ";
        s=to_string(nums);
        l=0;
        int b=0;
        if(s[0]=='1'){
            int j=0;
            while(s[j]=='1' || s[j]=='0'){
                j++;
            }
            l=j%n;
        }
       
        k=s[l];
        if(l!=0 ){
            for(int i=l;i<n;i++){
                if(s[i]==k ){

                    s[i]='0';
                }
            }
        }
        else{
             for(int i=0;i<n;i++){
                if(s[i]==k){
                    s[i]='1';
                }
            }

        }
        b=stoi(s);
        cout<<b<<" ";
        return a-b;

    }
};