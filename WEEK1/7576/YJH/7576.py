#7576
from collections import deque
import sys

input = sys.stdin.readline

dy = [-1,0,1,0]
dx = [0,1,0,-1]

def bfs(graph,tomato_exist):

    queue = deque()

    for tomato_y,tomato_x in tomato_exist:
        queue.append((tomato_y,tomato_x))
        
    while queue:
        y,x = queue.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny <0 or ny >= N or nx < 0 or nx >= M:
                continue

            if graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                queue.append((ny,nx))


if __name__ == '__main__':

    M, N = map(int, input().split())
    graph = []
    Max = 0
    tomato_exist = []
    flag = True
    
    for i in range(N):
        graph.append(list(map(int, input().split())))

        for k in range(M):
            if graph[i][k] == 1:
                tomato_exist.append((i,k))
                #토마토 있는 부분 기록
    
    bfs(graph, tomato_exist)

    for i in range(N): # 그래프에서 가장 큰 값과 가장 작은 값 찾아내기
        for k in range(M):
            if graph[i][k] > Max:
                Max = graph[i][k]
                
            if graph[i][k] == 0 :
                flag = False
                
    if flag == True:
        print(Max-1)
    else:
        print(-1)
