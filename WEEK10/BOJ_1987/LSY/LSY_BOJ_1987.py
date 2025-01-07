def movecount(R, C, board):
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    def dfs(x, y, visited):
        max_count = len(visited)

        for dx, dy in directions:
            nx = x + dx 
            ny = y + dy
            
            if 0 <= nx < R and 0 <= ny < C and board[nx][ny] not in visited:      #새로운 칸으로 이동           
                visited.add(board[nx][ny])
                max_count = max(max_count, dfs(nx, ny, visited))
                visited.remove(board[nx][ny])  

        return max_count

    return dfs(0, 0, {board[0][0]})

R, C = map(int, input().split())
board = [input().strip() for _ in range(R)]

print(movecount(R, C, board))
