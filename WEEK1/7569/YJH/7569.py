#7569
import sys
from collections import deque

input = sys.stdin.readline

dz = [-1,0,0,0,0,1]
dy = [0,-1,0,1,0,0]
dx = [0,0,1,0,-1,0]


def bfs(graph, tomato_exist):
    queue = deque()    

    for tomato_z,tomato_y,tomato_x in tomato_exist:
        queue.append((tomato_z,tomato_y,tomato_x))

    while queue:
        z,y,x = queue.popleft()

        for i in range(6):
            nz = z + dz[i]
            ny = y + dy[i]
            nx = x + dx[i]

            if nz < 0 or ny < 0 or nx < 0 or nz >= H or ny >= N or nx >= M:
                continue

            if graph[nz][ny][nx] == 0:
                graph[nz][ny][nx] = graph[z][y][x] + 1
                queue.append((nz,ny,nx))


if __name__ == "__main__":
    M,N,H = map(int,input().split())
    tomato_exist = []
    graph = [[[] for k in range(N)] for i in range(H)]
    Max = 0
    flag = False

    for i in range(H):
        for k in range(N):
            graph[i][k] = list(map(int, input().split()))
            #컴프리핸션 + for문으로 3차원 배열 만들기
            for j in range(M):
                if graph[i][k][j] == 1:
                    tomato_exist.append((i,k,j))


    bfs(graph, tomato_exist)

    for i in range(H):
        for k in range(N):
            for j in range(M):
                if graph[i][k][j] > Max:
                    Max = graph[i][k][j]

                if graph[i][k][j] == 0:
                    flag = True


    if flag == True:
        print(-1)

    else :
        print(Max-1)

    #print(*graph, sep = '\n')
