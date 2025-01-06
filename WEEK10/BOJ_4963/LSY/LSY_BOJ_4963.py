from collections import deque

def count_islands(w, h, grid):
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    
    def bfs(x, y):
        queue = deque([(x, y)])
        grid[y][x] = 0  # 방문한 곳은 0으로 변경
        while queue:
            cx, cy = queue.popleft()
            for dx, dy in directions:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < w and 0 <= ny < h and grid[ny][nx] == 1:
                    grid[ny][nx] = 0  # 방문 처리
                    queue.append((nx, ny))
    
    island_count = 0
    for y in range(h):
        for x in range(w):
            if grid[y][x] == 1:  # 새로운 섬 발견
                bfs(x, y)
                island_count += 1
    
    return island_count



while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    grid = [list(map(int, input().split())) for _ in range(h)]
    print(count_islands(w, h, grid))
