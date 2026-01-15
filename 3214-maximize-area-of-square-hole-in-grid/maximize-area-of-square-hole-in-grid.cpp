class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars),end(hBars));
        sort(begin(vBars),end(vBars));
        int curwidth=1;
        int curheight=1;
        int maxw=1;
        int maxh=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                curheight++;
            }
            else{
                curheight=1;

            }
            maxh=max(maxh,curheight);
        }
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                curwidth++;
            }
            else{
                curwidth=1;
            }
            maxw=max(curwidth,maxw);
        }
        cout<<maxw<<maxh<<endl;
        int area=pow(min(maxw,maxh)+1,2);
        return area;
    }
};