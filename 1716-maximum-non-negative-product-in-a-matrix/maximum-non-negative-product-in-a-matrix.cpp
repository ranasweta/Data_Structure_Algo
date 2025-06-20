class Solution {
public:
typedef long long ll;
int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //bottom up dp array
        vector<vector<pair<ll,ll>>>t(m,vector<pair<ll,ll>>(n));
        t[0][0]={grid[0][0],grid[0][0]};
        //fillinf 1st row
        for(int i=1;i<n;i++){
            t[0][i].first=t[0][i-1].first*grid[0][i];
            t[0][i].second=t[0][i-1].second*grid[0][i];
        }
        for(int i=1;i<m;i++){
            t[i][0].first=t[i-1][0].first*grid[i][0];
            t[i][0].second=t[i-1][0].second*grid[i][0];

        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=t[i-1][j].first;
                ll upmin=t[i-1][j].second;
                ll leftmax=t[i][j-1].first;
                ll leftmin=t[i][j-1].second;
                t[i][j].first=max({upmax*grid[i][j],upmin*grid[i][j],leftmax*grid[i][j],leftmin*grid[i][j]});
                t[i][j].second=min({upmax*grid[i][j],upmin*grid[i][j],leftmax*grid[i][j],leftmin*grid[i][j]});

            }
        }
auto[mx,mn]=t[m-1][n-1];
return mx>=0?mx%mod:-1;
        
    }
};