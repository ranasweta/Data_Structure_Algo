from collections import defaultdict, deque
class Solution:
    #directed array is given bfs
    def bfs(self,u,visited,adj):
        q=deque()
        q.append(u)

        visited[u]=1
        while  q:
            k=q.popleft()
            for v in adj[k]:
                if  not visited[v]:
                    visited[v]=1
                    q.append(v)
       
        




    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj=defaultdict(list)
        for i in range(len(invocations)):
            u=invocations[i][0]
            v=invocations[i][1]
            adj[u].append(v)
        visited=[0]*n
        self.bfs(k,visited,adj)
        # now we will search in the invocations if that suspecious is indegree by unsuspecious
        for u,v in invocations:
            if not visited[u] and visited[v]:
                return list(range(n))# as all will be nullified 
        ans=[]
        for i in range(n):
            if not visited[i]:
                ans.append(i)
        return ans

            
        



        
        