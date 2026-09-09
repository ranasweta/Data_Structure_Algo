class Solution:
    def countCommas(self, n: int) -> int:
        if n-1000<0:
            return 0
        elif n-1000==0:
            return 1
        else:
             l=len(str(n))
             return ((l-1)//3)*(n-1000)+1
        