class Solution {
public: // brute force
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> Room(n, 0); // for counting rooms used
        sort(begin(meetings), end(meetings));
        vector<long long> lastAvailableAt(n,0); // these are meeting rooms which will be storing last available
        for (auto meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;

            long long earlyMeetTime =
                LLONG_MAX; // which meet will end and what is its duration
            int earlyMeet = 0;
            for (int room = 0; room < n; room++) {
                if (lastAvailableAt[room] <=start) {
                    lastAvailableAt[room] = end;
                    found = true;
                    Room[room]++;
                    break;
                }
                if (lastAvailableAt[room] < earlyMeetTime) {
                    earlyMeetTime = lastAvailableAt[room];

                    earlyMeet = room;
                }
            }
            // no room empty
            if (!found) {
                // pick that one which will end early
                lastAvailableAt[earlyMeet] += duration;
                Room[earlyMeet]++;
            }
        }
        int maxUsedRoom = -1;
        int maxUsed = 0;
        for (int i = 0; i < n; i++) {
            if (Room[i] > maxUsed) {
                maxUsed = Room[i];
                maxUsedRoom = i;
            }
        }
        return maxUsedRoom;
    }
};