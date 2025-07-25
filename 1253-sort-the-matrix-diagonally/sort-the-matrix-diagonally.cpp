class Solution {
public://i-j = const
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>> mp;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto & [key,value]: mp){
            sort(begin(value),end(value));
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                mat[i][j]=mp[i-j].back();
                mp[i-j].pop_back();

            }
        }
        return mat;
    }
};