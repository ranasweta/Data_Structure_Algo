class Solution {
public://brute greedy
    int maxOperations(string s) {
       vector<int> one;
       int i=0;
       while (i<s.size()){
        int gr=0;
        if(s[i]=='0') i++;
        while(i<s.size() && s[i]=='1'){
            gr++;
            i++;
        }
        if(i<s.size() && gr>0){
            one.push_back(gr);
        }


       }
        int temp=0;
        int ans=0;
       for(int n: one){
        temp+=n;
        ans+=temp;
        cout<<n<<endl;
       }
       return ans;
    }
};