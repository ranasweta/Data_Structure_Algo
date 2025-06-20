class Solution {
public://good question for oa
    int maxDistance(string st, int k) {
        int n=0;
        int s=0;
        int e=0;
        int w=0;
        int mx=0;
        for(int i=0;i<st.length();i++){
            if(st[i]=='E'){
                e+=1;
            }
            else if(st[i]=='W'){
                w+=1;
            }
            else if(st[i]=='N'){
                n+=1;
            }
            else if(st[i]=='S'){
                s+=1;
            }
             int manhattan =abs(e-w)+abs(n-s);
            int steps=i+1;
            int waste=steps-manhattan;//the steps wasted 
            int curr_needed=0;
            if(steps!=manhattan){
                curr_needed=min(2*k,waste);
            }
            manhattan+=curr_needed;
            mx=max(mx,manhattan);
        }
        return mx;
    }
};