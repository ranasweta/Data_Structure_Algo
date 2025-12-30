class Solution {
public:
    bool isMagicGrid(vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int val = grid[r+i][c+j];
                if(val < 1 || val > 9 || st.count(val)) return false;
                st.insert(val);
            }
        }
        
        int target = grid[r][c] + grid[r][c+1] + grid[r][c+2]; // first row sum
        
        // check rows
        for(int i=0;i<3;i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != target) return false;
        }
        
        // check columns
        for(int j=0;j<3;j++){
            if(grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != target) return false;
        }
        
        // check diagonals
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != target) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != target) return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(isMagicGrid(grid,i,j)) res++;
            }
        }
        return res;
    }
};