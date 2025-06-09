class Solution {
public:
    long Count(long curr,long nxt,int n){
        int cnt=0;
        while(curr<=n){
            cnt+=nxt-curr;
            curr*=10;
            nxt*=10;
            nxt=min(nxt,long(n+1));//very crucial as curr =next+1 hence if curr=n then nxt =n+1
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k-=1; //since we started from 1st number so we will remove that from k to mark it counted
        while(k>0){
            int cnt=Count(curr,curr+1,n);
            if(cnt<=k){
            curr++;
            k-=cnt;//slipping ekements in the prefix tree
            }
            else{
                    curr*=10;
                    k-=1;
            }
        }
        return curr;
    }
};