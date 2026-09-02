class Solution:
    def isHappy(self, n: int) -> bool:
        
            sum=0
            s=set()
            while sum!=1:
                sum=0
                while n:
                    sum+=(n%10)**2
                    n=n//10
                if sum in s:
                    return False
                s.add(sum)
                
                n=sum
            return True

