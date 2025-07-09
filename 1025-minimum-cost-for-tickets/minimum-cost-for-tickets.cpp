class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //t[i]= min cost till day i
        int n=days.back();
        vector<int>t(n+1);
        t[0]=0;
        unordered_set<int>st(begin(days),end(days));
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                t[i]=t[i-1];
            }
            else{
            int d1=costs[0]+t[max(i-1,0)];
            int d7=costs[1]+t[max(i-7,0)];
            int d30=costs[2]+t[max(i-30,0)];
            t[i]=min({d1,d7,d30});

            }
        }
        return t[n];
    }
};