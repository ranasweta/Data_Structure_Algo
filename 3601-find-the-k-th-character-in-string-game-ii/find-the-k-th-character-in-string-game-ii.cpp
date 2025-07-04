class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //base 
        if(k==1) return 'a';
        long long newk=-1;
        int n=operations.size();
        long long len=1;
        int op;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                newk=k-len/2;   
                op=operations[i];
                break;
            }
        }
        char ch=kthCharacter(newk,operations);
        if(op==0){
            return ch;
        }
        return ch=='z'?'a':ch+1;
    }
};