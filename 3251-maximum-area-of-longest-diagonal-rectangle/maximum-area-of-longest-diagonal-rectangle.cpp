class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=INT_MIN;
        double maxDiagonal=INT_MIN;
        for(auto & d:dimensions){
            int l=d[0];
            int w=d[1];
            double diagonal=sqrt( l*l + w*w );
            int area=l*w;
            if(diagonal>maxDiagonal){
                maxArea = area;
                maxDiagonal = diagonal;
            }
            else if(diagonal == maxDiagonal){
                maxArea=max(area,maxArea);

            }
            
        }
        return maxArea;
    }
};