from collections import deque

def bfs(maze, n, m):
    # 방향 (상, 하, 좌, 우)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    # 방문 여부와 거리 저장을 위한 큐
    queue = deque([(0, 0)])  # 시작 위치 (0, 0)
    
    while queue:
        x, y = queue.popleft()
        
        # 네 방향으로 이동
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            
            # 범위 안에 있고 이동 가능한 경우
            if 0 <= nx < n and 0 <= ny < m and maze[nx][ny] == 1:
                # 방문하지 않았다면
                if maze[nx][ny] == 1:
                    # 거리 갱신 및 큐에 추가
                    maze[nx][ny] = maze[x][y] + 1
                    queue.append((nx, ny))
    
    # 도착 위치의 거리 반환
    return maze[n - 1][m - 1]

# 입력 처리
n, m = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(n)]

# 결과 출력
print(bfs(maze, n, m))
