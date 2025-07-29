class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while(a ||b ||c ){
            if(c&1){
                if(!(a&1) && !(b&1)){
                    flip++;
                }
            }
            else{
                if(a&1){
                    flip++;
                }
                if(b&1){
                    flip++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
            cout<<a<<b<<c<<endl;
            cout<<flip<<endl;
        }
        return flip;
    }
};