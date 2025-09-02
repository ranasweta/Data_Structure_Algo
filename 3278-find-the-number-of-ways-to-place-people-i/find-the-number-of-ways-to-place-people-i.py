class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        points.sort(key = lambda x:(x[1],x[0]))
        n = len(points)

        def check(i,j):
            x_min = min(points[i][0],points[j][0])
            x_max = max(points[i][0],points[j][0])
            y_min = min(points[i][1],points[j][1])
            y_max = max(points[i][1],points[j][1])
            for idx,(x,y) in enumerate(points):
                if idx == i or idx == j:
                    continue
                if x_min <= x <= x_max and y_min <= y <= y_max:
                    return False
            return True

        for i in range(n):
            for j in range(i+1,n):
                x1,y1 = points[i]
                x2,y2 = points[j]
                if x2-x1 == 0 or ((y2-y1) / (x2-x1)) <= 0:
                    if check(i,j):
                        ans += 1
        return ans
