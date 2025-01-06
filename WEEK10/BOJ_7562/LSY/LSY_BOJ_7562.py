from collections import deque

def knight_moves(l, start, end):
    
    directions = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)] # 나이트의 이동 방향
    

    queue = deque([(*start, 0)])   # BFS를 위한 큐 초기화 
    visited = [[False] * l for _ in range(l)]
    visited[start[1]][start[0]] = True
    
    while queue:
        x, y, moves = queue.popleft()
        
        if (x, y) == end:
            return moves
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < l and 0 <= ny < l and not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((nx, ny, moves + 1))

t = int(input()) 
results = []
for _ in range(t):
    l = int(input())  
    start = tuple(map(int, input().split()))  
    end = tuple(map(int, input().split()))  
    results.append(knight_moves(l, start, end))
    
for result in results:
    print(result)

