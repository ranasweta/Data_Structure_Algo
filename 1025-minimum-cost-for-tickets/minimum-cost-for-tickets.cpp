class Solution {
public:
int t[366];
int n;
int solve(int i,vector<int>& days, vector<int>& costs){
    if(i>=n){
        return 0;
    }
    if(t[i]!=-1) return t[i];
    //1st day
    int cost_1=costs[0]+solve(i+1,days,costs);
    //7 day
    int max_day=days[i]+7;
    int j=i;
    while(j<n && days[j]<max_day){
        j++;
    }
    int cost_7=costs[1]+solve(j,days,costs);
    //30 day
     max_day=days[i]+30;
    j=i;
    while(j<n && days[j]<max_day){
        j++;
    }
    int cost_30=costs[2]+solve(j,days,costs);
    return t[i]=min({cost_1,cost_7,cost_30});



}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      n=days.size();
      memset(t,-1,sizeof(t));
      return solve(0,days,costs);  
    }
};