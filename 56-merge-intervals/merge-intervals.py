class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        n = len(intervals)
        i = 0
        ans = []

        while i < n:
            cs = intervals[i][0]
            ce = intervals[i][1]

            j = i + 1

            while j < n and ce >= intervals[j][0]:
                ce = max(ce, intervals[j][1])
                j += 1

            ans.append([cs, ce])
            i = j

        return ans