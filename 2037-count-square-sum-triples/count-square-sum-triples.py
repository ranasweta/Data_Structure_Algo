class Solution:
    def countTriples(self, n: int) -> int:
        cnt=0
        for i in range(1,n+1):
            for j in range(i+1,n+1):
                if math.sqrt(i**2+j**2) in range(j+1,n+1):
                    cnt+=1
        return cnt*2
        