class Solution:
    def secondHighest(self, s: str) -> int:
        maxx = -float('inf')
        second = -float('inf')
        for i in s:
            if i.isnumeric():
                x = int(i)
                if x > maxx:
                    second = maxx
                    maxx = x
                elif x > second and x != maxx:
                    second = x
        return second if second != -float('inf') else -1
                    