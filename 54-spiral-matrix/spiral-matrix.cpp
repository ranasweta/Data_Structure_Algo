class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();//row
        int n=matrix[0].size();//col
        int dir=0;
        /*\     const       dir
        dir=0    Top        Left->right
        1        Right      top->down
        2        Down       right->left
        3        Left       down->top
        */
        vector<int > result;
        int left=0,top=0;
        int right=n-1,down=m-1;
        while(top<=down && left <= right ){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=down;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[down][i]);

                }
                down--;
            }
            else{
                for(int i=down;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir= (dir+1)%4;
        }
        return result;
    }
};