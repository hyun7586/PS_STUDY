#14502
from collections import deque
import sys
import itertools
import copy

input = sys.stdin.readline

dy = [-1,0,1,0]
dx = [0,1,0,-1]

def bfs(virus_group,graph_copy):
    queue = deque()

    for virus_y,virus_x in virus_group:
        queue.append((virus_y,virus_x))

    while queue:

        y,x = queue.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny <0 or ny >= N or nx < 0 or nx >= M:
                continue

            if graph_copy[ny][nx] == 0:
                graph_copy[ny][nx] = -1 #방문표시
                queue.append((ny,nx))
        

if __name__ == '__main__':
    N,M = map(int,input().split())
    graph = []
    wall_record = []
    empty = []
    virus_group = []
    Max = 0
    
    for i in range(N):
        graph.append(list(map(int, input().split())))

        for k in range(M):
            if graph[i][k] == 0:
                wall_record.append((i,k))

            if graph[i][k] == 1:
                 empty.append((i,k))   

            if graph[i][k] == 2:
                virus_group.append((i,k))

    walls_group = list(itertools.combinations(wall_record,3))

    
    for walls in walls_group:

        #graph_copy = copy.deepcopy(graph)
        graph_copy = [[0 for i in range(M)] for k in range(N)]
        count = 0
        
        for empty_y,empty_x in empty:
            graph_copy[empty_y][empty_x] = 1

        for virus_y,virus_x in virus_group:
            graph_copy[virus_y][virus_x] = 2
        
        for wall_y,wall_x in walls:
            graph_copy[wall_y][wall_x] = 1

        bfs(virus_group,graph_copy)

        for i in range(N):
            for k in range(M):
                if graph_copy[i][k] == 0:
                    count += 1

        if Max < count:
            Max = count
                    

    print(Max)
