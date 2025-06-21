class Solution {
public://bfs
    vector<vector<int>> direction={{0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>que;
        if(grid[0][0]==1){
            return -1;
        }
        auto isSafe = [&] (int x,int y){
            return x>=0 && y>=0 && x<n && y<n;
        };
        que.push({0,0});
        grid[0][0]=1;
        int level=0;
        while(!que.empty()){
            int N=que.size();
            while(N--){
                auto curr=que.front();
                que.pop();
                int x=curr.first;
                int y=curr.second;
                if(x==n-1 && y==n-1){
                    return level+1;
                }
                for(auto & dir:direction){
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                        if(isSafe(x_,y_) && grid[x_][y_]==0){
                            que.push({x_,y_});
                            grid[x_][y_]=1;

                        }

                }
            }
            level++;
        }
        return -1;
    }
};