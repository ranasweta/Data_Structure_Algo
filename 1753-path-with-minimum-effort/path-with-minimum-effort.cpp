class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int m,n;
    bool CheckValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<int>>r(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        r[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dif=pq.top().first;
            auto coord=pq.top().second;
            int x=coord.first;
            int y=coord.second;
            pq.pop();
            for(auto & dir:dirs){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(CheckValid(x_,y_)){
                    int absdif=abs(heights[x][y]-heights[x_][y_]);
                    int mx=max(dif,absdif);
                    if(r[x_][y_]>mx){

                        r[x_][y_]=mx;
                        pq.push({mx,{x_,y_}});
                    
                    }
                }
            }
        }
        return r[m-1][n-1];
    }
};