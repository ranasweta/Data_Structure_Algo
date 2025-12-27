class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomUsage(n, 0); // to track number of meetings per room
        vector<long long> lastAvailableAt(n, 0); // when each room is free
        sort(meetings.begin(), meetings.end());

        for (auto& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            int availableRoom = -1;
            for (int i = 0; i < n; i++) {
                if (lastAvailableAt[i] <= start) {
                    if (availableRoom == -1 || i < availableRoom) {
                        availableRoom = i;
                    }
                }
            }

            if (availableRoom != -1) {
                lastAvailableAt[availableRoom] = end;
                roomUsage[availableRoom]++;
            } else {
                // Find the room that becomes available the earliest
                long long minTime = LLONG_MAX;
                int chosenRoom = -1;
                for (int i = 0; i < n; i++) {
                    if (lastAvailableAt[i] < minTime) {
                        minTime = lastAvailableAt[i];
                        chosenRoom = i;
                    }
                }
                lastAvailableAt[chosenRoom] += duration;
                roomUsage[chosenRoom]++;
            }
        }

        int mostUsedRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomUsage[i] > roomUsage[mostUsedRoom]) {
                mostUsedRoom = i;
            }
        }

        return mostUsedRoom;
    }
};
