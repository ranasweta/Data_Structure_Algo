class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int m=INT_MIN;
        for(int i=1;i<points.size();i++){
            m=max(m,points[i][0]-points[i-1][0]);
        }
        return m;

    }
};