class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans=list()
        for i in range(len(nums)):
            num=nums[i]
            emp=list()
            while num:
                emp.append(num%10)
                num=num//10
            for i in range(len(emp)-1,-1,-1):
                ans.append(emp[i])
        return ans