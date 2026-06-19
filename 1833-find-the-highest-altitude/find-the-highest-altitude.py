class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxi=0
        c=0
        for i in gain:
            c+=i
            maxi=max(maxi,c)
        return maxi
        