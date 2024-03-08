from collections import deque

vertics, edge, start = map(int,input().split())
graph = [[] for i in range(vertics+1)]
visited_dfs = [False] * (vertics+1)
visited_bfs = [False] * (vertics+1)


for i in range(edge):
    num1, num2 = map(int,input().split())
    graph[num1].append(num2)
    graph[num2].append(num1)
    graph[num1] = sorted(graph[num1])
    graph[num2] = sorted(graph[num2])

def dfs(start, graph):
    if not visited_dfs[start]:
        visited_dfs[start] = True
        print(start, end = ' ')
    
        for vertic in graph[start]:
            dfs(vertic, graph)


def bfs(start, graph):
    queue = deque()
    queue.append(start)

    while queue:
        num = queue.popleft()
        visited_bfs[num] = True
        print(num, end = " ")
        
        for vertic in graph[num]:
            if not visited_bfs[vertic]:
                visited_bfs[vertic] = True
                queue.append(vertic)


dfs(start, graph)
print()
bfs(start, graph)
