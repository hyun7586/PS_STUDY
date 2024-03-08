import sys
from collections import deque

input = sys.stdin.readline

def bfs(start,graph):
    queue = deque()
    queue.append(start)

    while queue:
        num = queue.popleft()
        visited[num] = True

        for vertic in graph[num]:
            if not visited[vertic]:
                visited[vertic] = True
                queue.append(vertic)
                
        
if __name__ == '__main__':
    
    N, M = map(int, input().split())
    graph = [[] for i in range(N+1)]
    visited = [False] * (N+1)
    count = 0
    
    for i in range(M):
        num1, num2 = map(int, input().split())
        
        graph[num1].append(num2)
        graph[num2].append(num1)
        #graph[num1] = sorted(graph[num1])
        #graph[num2] = sorted(graph[num2])

    for i in range(1,N+1):
        if not visited[i]:
            bfs(i,graph)
            count += 1
            
    print(count)
