class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool right = (i == 0) || (flowerbed[i - 1] == 0);
                bool left =
                    (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                if (right && left) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};