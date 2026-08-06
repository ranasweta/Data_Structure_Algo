class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def func(nm):
                a=1
                
                while nm:
                    a=a*(nm%10)
                    nm=nm//10
                return a
        
        for i in range(n,101):
            if(func(i)%t==0):
                return i



        