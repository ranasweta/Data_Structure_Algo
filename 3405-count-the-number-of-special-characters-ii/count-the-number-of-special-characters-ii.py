class Solution:#brute
    def numberOfSpecialChars(self, word: str) -> int:
        ans=0
        n=len(word)
        upper=[-1]*26
        lower=[-1]*26
        for i in range(n):
            if word[i].isupper() and upper[ord(word[i])-ord('A')]==-1 :
                
                upper[ord(word[i])-ord('A')]=i
            elif word[i].islower():
                lower[ord(word[i])-ord('a')]=i
        for i in range(26):
            print(lower[i],upper[i])
            if lower[i]<upper[i] and (lower[i]!=-1 and upper[i]!=-1):
                ans+=1
        return ans

        