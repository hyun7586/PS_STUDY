import sys
from collections import deque

input = sys.stdin.readline

dy = [-1,0,1,0]
dx = [0,1,0,-1]


def bfs(y,x, graph, maze):
    queue = deque()
    queue.append((y,x))

    while queue:

        y,x = queue.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or ny >=N or nx<0 or nx >=M:
                continue

            if ny == 0 and nx == 0 :
                continue
        
            if graph[ny][nx] == '1':
                queue.append((ny,nx))
                graph[ny][nx] = '0'
                maze[ny][nx] = maze[y][x] + 1
                

if __name__ == "__main__":
    N,M = map(int, input().split())
    graph = []
    maze = [[0 for i in range(M)] for k in range(N)]
    maze[0][0] = 1 #시작점인 (0,0)은 항상 갈 수 있는 1로 표시
    
    for i in range(N):
        graph.append(list(input().rstrip()))
        #띄어쓰기 없이 입력받으므로 list형으로 입력을 받는다.

    bfs(0,0,graph,maze)

    print(maze[N-1][M-1])
