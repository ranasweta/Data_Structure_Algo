class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> ans(n+1,0.000000);
        ans[0]=1.000000;
        double probSum=(k==0)?0.0:1.000000;
        for(int i=1;i<=n;i++){
            ans[i]=probSum/maxPts;
            if(i<k){
                probSum+=ans[i];
            }
            if((i-maxPts)>=0 && (i-maxPts)<k){
                probSum-=ans[i-maxPts];
            }

        }
        double res=0.000000;
        for(int i=k;i<=n;i++){
            res+=ans[i];
        }
        return res;
    }
};