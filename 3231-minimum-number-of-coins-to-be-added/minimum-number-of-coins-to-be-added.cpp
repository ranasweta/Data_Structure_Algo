class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int totalCoinsRequired = 0;
        int obtainable = 0;
        // for taking min
        sort(begin(coins), end(coins));
        for (auto coin : coins) {
            while (coin > obtainable + 1) {
                totalCoinsRequired++;
                obtainable += obtainable + 1;
                if (obtainable >= target)
                    return totalCoinsRequired;
            }
            obtainable += coin;
            if (obtainable >= target)
                return totalCoinsRequired;
        }
        // incase we havent reaced and our coins are finished
        while (obtainable < target) {
            totalCoinsRequired++;
            obtainable += obtainable + 1;
        }
        return totalCoinsRequired;
        ;
    }
};