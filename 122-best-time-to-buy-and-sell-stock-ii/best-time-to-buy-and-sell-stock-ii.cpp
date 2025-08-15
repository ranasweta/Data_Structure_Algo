class Solution {
public:
/*
buy at lowest(aage piche wale bade honge)
sell at peak (aage piche wale chote honge)
usually we want to check if next day is greater then prev day or not 
*/
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=(prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
};