
class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        n= []
        for num in nums:
            if num%k==0 and num not in n:
                n.append(num)
        n.sort()
        
        print(n)
        i=1
        for ni in n:
            if k*i!=ni:
                return k*i
            i+=1
        return k*i



        