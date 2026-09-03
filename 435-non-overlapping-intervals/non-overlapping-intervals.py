class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        i = 0
        j = 1
        cnt = 0
        n = len(intervals)

        while j < n:
            ce = intervals[i][1]
            ns = intervals[j][0]
            ne = intervals[j][1]

            if ce <= ns:
                # No overlap
                i = j
                j += 1

            else:
                # Overlap → remove one interval
                cnt += 1

                # Keep the interval with smaller end time
                if ne < ce:
                    i = j

                j += 1

        return cnt