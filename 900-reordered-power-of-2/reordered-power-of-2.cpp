class Solution {
public:
//similar to matching anagrams
    string toString(int n){
        string s=to_string(n);
        sort(begin(s),end(s));
        return s;
    }
    bool reorderedPowerOf2(int n) {
        //2^29 is the highest under 10^9 value
        string s=toString(n);
        for(int p=0;p<=29;p++){
            if(s==toString(1<<p)){
                return true;
            }
        }
        return false;
    }
};