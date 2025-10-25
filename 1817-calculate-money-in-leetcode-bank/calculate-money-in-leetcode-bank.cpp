class Solution {
public:
    int totalMoney(int n) {
        int counter=0;
            int daysleft=n;
            int ans=0;
        while(daysleft>0){
            int day=counter+min(7,daysleft);
            ans+=((day)*(day+1)/2)-((counter)*(counter+1)/2);
            daysleft-=min(7,daysleft);
            counter++;
            cout<<day<<" "<<ans<<" "<<daysleft<<" "<<counter<<endl;
        }
        return ans;
    }
};