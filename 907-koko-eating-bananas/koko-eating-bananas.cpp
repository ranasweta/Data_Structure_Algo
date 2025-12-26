class Solution {
public://easy peasy
    bool canEat(vector<int>& piles, int h,int mid){
        int hour=0;
        for(int &p:piles){
            hour+=(p/mid);
            if((p%mid)){
                hour++;
            }
        }
        return h>=hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(begin(piles),end(piles));
        while(l<r){
            int mid=l+(r-l)/2;
            if(canEat(piles,h,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }

        }
        return l;
    }
};