class Solution {
public://two pointer greedy question keep the max height and move tthat height which is smaller one 
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
        while(i<j){
            int h=min(height[i],height[j]);
            int w=j-i;
            area = max(area,h*w);
            if(height[i]>=height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return area;
    }
};