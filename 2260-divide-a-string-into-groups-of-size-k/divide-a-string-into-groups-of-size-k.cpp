class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        int cnt=0;
        vector<string> r;
        for(int i=0;i<n;i++){
            if(i%k==0){
                if(i+k-1>n){
                    r.push_back(s.substr(i,n-i));
                }
                else{

                r.push_back(s.substr(i,k));
                }
        }}
        if(r[r.size()-1].size()<k){
            while(r[r.size()-1].size()!=k){
            r[r.size()-1].push_back(fill);
            }
        }
        return r;
    }
};