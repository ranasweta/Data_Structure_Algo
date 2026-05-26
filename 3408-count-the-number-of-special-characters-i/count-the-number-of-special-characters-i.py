class Solution:#brute
    def numberOfSpecialChars(self, word: str) -> int:
        ans=0
        upper=[0]*26
        lower=[0]*26
        for i in word:
            if i.isupper():
                upper[ord(i)-ord('A')]=1
            else:
                lower[ord(i)-ord('a')]=1
        for i in range(26):
            ans+=upper[i]&lower[i]
        return ans

        