class Solution {
public:
    vector<vector<string>> result;
    bool check(vector<string>& board, int row, int col,int n){
        //upper matlab rows chNGEE
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }

        }
        //right diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&& j<n;i--,j++){
             if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>& board, int row, int n) {
        if (row >= n) {
            result.push_back(board); // if we reached last row means our ans is ready
            return;
        }
        for (int col = 0; col < n; col++) {
            if (check(board, row, col,n)) {
                board[row][col] = 'Q';
                solve(board, row + 1,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return result;
    }
};