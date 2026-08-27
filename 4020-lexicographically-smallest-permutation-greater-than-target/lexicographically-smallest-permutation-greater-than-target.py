import bisect
class Solution:
    def lexGreaterPermutation(self,s:str,target:str)->str:
        n=len(s)
        d=Counter(s)
        a=sorted(s)
        p=[]
        for i in range(n):
            if target[i] in d:
                d[target[i]]-=1
                if d[target[i]]==0: del d[target[i]]
                p.append(target[i])
            else:
                break
        i=len(p)
        if i<n:
            j=bisect.bisect_right(a,target[i])
            while j<n and d.get(a[j],0)==0:
                j+=1
            if j<n:
                p.append(a[j])
                d[a[j]]-=1
                if d[a[j]]==0: del d[a[j]]
                for c in a:
                    if d.get(c,0):
                        p.append(c)
                        d[c]-=1
                return ''.join(p)
        for i in range(len(p)-1,-1,-1):
            d[target[i]]=d.get(target[i],0)+1
            j=bisect.bisect_right(a,target[i])
            while j<n and d.get(a[j],0)==0:
                j+=1
            if j<n:
                q=list(target[:i])
                q.append(a[j])
                d[a[j]]-=1
                if d[a[j]]==0: del d[a[j]]
                for c in a:
                    if d.get(c,0):
                        q.append(c)
                        d[c]-=1
                return ''.join(q)
        return ""