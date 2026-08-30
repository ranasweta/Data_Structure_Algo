class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        numin=min(nums)
        numax=max(nums)

        indmin=0
        indmax=0
        for i in range(len(nums)):

            if nums[i]==numin:
                indmin=i
            elif nums[i]==numax:
                indmax=i
            else:
                continue
        n=len(nums)
        if indmin>indmax:
            indmax,indmin=indmin,indmax
        
        ans=min([n-indmax+indmin+1,indmax+1,n-indmin])
        return ans
