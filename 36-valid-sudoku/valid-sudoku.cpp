class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        // Check rows
        for(int i = 0; i < 9; i++) {
            set<char> st;
            for(int j = 0; j < 9; j++) {
                if(grid[i][j] != '.') {
                    if(st.find(grid[i][j]) != st.end()) return false;
                    st.insert(grid[i][j]);
                }
            }
        }

        // Check columns
        for(int i = 0; i < 9; i++) {
            set<char> st;
            for(int j = 0; j < 9; j++) {
                if(grid[j][i] != '.') {
                    if(st.find(grid[j][i]) != st.end()) return false;
                    st.insert(grid[j][i]);
                }
            }
        }

        // Check 3x3 boxes
        for(int sr = 0; sr < 9; sr += 3) {
            for(int sc = 0; sc < 9; sc += 3) {
                set<char> st;
                for(int i = sr; i < sr + 3; i++) {
                    for(int j = sc; j < sc + 3; j++) {
                        if(grid[i][j] != '.') {
                            if(st.find(grid[i][j]) != st.end()) return false;
                            st.insert(grid[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }
};