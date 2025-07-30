class Solution {
public:
    int countOnes(int num){//TC log(num) as there are log(num) bits
        int cnt=0;
        while(num){
            cnt+=(num&1);
            num>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[&](int &a,int &b){
            int count_a=__builtin_popcount(a);
            int count_b=__builtin_popcount(b);
            if(count_a==count_b){
                return a<b;
            }
            return count_a<count_b;
        };
        sort(begin(arr),end(arr),lambda);//O(nlogn)
        return arr;
    }
};