from collections import deque

def find_fastest_time(N, K):
    max_pos = 100000
    visited = [-1] * (max_pos + 1)
    queue = deque([N])
    visited[N] = 0  # 시작 위치 방문 표시
    
    while queue:
        current = queue.popleft()
        
        if current == K:
            return visited[current] # 동생을 찾으면 시간을 반환
        
        for next_pos in (current - 1, current + 1, current * 2):
            if 0 <= next_pos <= max_pos and visited[next_pos] == -1: #다음 위치 방문 X
                visited[next_pos] = visited[current] + 1
                queue.append(next_pos)

N, K = map(int, input().split())

print(find_fastest_time(N, K))
