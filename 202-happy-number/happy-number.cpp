class Solution {
public:
    bool isHappy(int n) {
        set<string> s;
        string curr=to_string(n);
        int sum=0;
        while(!s.count(curr)){
            for(int i=0;i<curr.size();i++){
                sum+=(curr[i]-'0')*(curr[i]-'0');
            }
            if(sum==1) return true;
            s.insert(curr);
            curr=to_string(sum);
            sum=0;
            
        }
        return false;
    }
};