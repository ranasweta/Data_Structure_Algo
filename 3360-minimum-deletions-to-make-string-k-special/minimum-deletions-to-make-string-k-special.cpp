class Solution {
public:
    int minimumDeletions(string words, int k) {
        vector<int> freq(26,0);
        int n=words.size();
        for(char &i:words){
            freq[i-'a']++;
        }
        sort(begin(freq),end(freq));
        int r=words.length();
        int cumulative_del=0;//shuru ke sare del krne padenge before othe higher one
        for(int i=0;i<26;i++){
            int del=cumulative_del;
            for(int j=25;j>i;j--){
                if(freq[j]-freq[i]<=k){
                    break;//no deletion 

                }
                del+=freq[j]-freq[i]-k;
            }
            r=min(del,r);
                cumulative_del+=freq[i];

        }

return r;
        
    }
};