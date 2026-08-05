from collections import defaultdict
class Solution:
    #directed array is given dfs
    def dfs(self,u,visited,adj):
        if(visited[u]==1): return

        visited[u]=1
        for v in adj[u]:
            if(not visited[v]) :
                self.dfs(v,visited,adj)
        




    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj=defaultdict(list)
        for i in range(len(invocations)):
            u=invocations[i][0]
            v=invocations[i][1]
            adj[u].append(v)
        visited=[0]*n
        self.dfs(k,visited,adj)
        # now we will search in the invocations if that suspecious is indegree by unsuspecious
        for u,v in invocations:
            if not visited[u] and visited[v]:
                return list(range(n))# as all will be nullified 
        ans=[]
        for i in range(n):
            if not visited[i]:
                ans.append(i)
        return ans

            
        



        
        