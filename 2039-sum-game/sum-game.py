class Solution:
    def sumGame(self, num: str) -> bool:
        n=len(num)
        l=r=0
        lsum=rsum=0
        for i in range(n//2):
            if num[i]=='?':
                l+=1
            else:
                lsum+=int(num[i])
        for i in range(n//2,n):
            if num[i]=='?':
                r+=1
            else:
                rsum+=int(num[i])
        left=2*lsum+9*l
        right=2*rsum+9*r
        if left==right:
            return False
        return True
        
        

        