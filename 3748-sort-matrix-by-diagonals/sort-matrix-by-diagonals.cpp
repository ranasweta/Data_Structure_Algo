class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            }

        }
        for(auto &[key,value]: mp){
            if(key<0){
                sort(begin(value),end(value),greater<int>());
            }
            else{
                sort(begin(value),end(value));
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};