class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for (int w : weights) {
            if (load + w > cap) {
                days++;
                load = 0;
            }
            load += w;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int d = findDays(weights, mid);
            if (d <= days) {
                ans = mid;          // record possible answer
                high = mid - 1;     // try to minimize capacity
            } else {
                low = mid + 1;      // increase capacity
            }
        }
        return ans;
    }
};
