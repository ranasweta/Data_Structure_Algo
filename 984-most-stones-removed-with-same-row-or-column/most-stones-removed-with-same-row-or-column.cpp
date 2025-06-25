class Solution {
public:
//group banate jao jiske bhi row and col milte jaa rhe jitne group honge unmese ek ek chutta jayega
    void dfs(vector<vector<int>>& stones,vector<bool>&visited,int indx){
        visited[indx]=true;

        for(int i=0;i<stones.size();i++){
            int r=stones[i][0];
            int c=stones[i][1];
            if(!visited[i] && (r==stones[indx][0] || c==stones[indx][1])){
                dfs(stones,visited,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>visited(n,false);
        int group=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(stones,visited,i);
            }
            else{
                continue;
            }
            group++;
        }
        return n-group;
    }
};