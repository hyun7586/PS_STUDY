import sys

input = sys.stdin.readline

def dp(N,M,graph):

    for i in range(N-2,-1,-1):
        for k in range(M):
            if graph[i][k] > 0: # 갈 수 있을 경우
                if k == 0:
                    graph[i][k] = graph[i+1][0] + graph[i+1][1]
                elif k == M-1:
                    graph[i][k] = graph[i+1][M-1] + graph[i+1][M-2]
                else:
                    graph[i][k] = graph[i+1][k-1] + graph[i+1][k] + graph[i+1][k+1]


if __name__ == '__main__':
    N, M = map(int, input().split())
    graph = []
    divide = 1000000007

    for i in range(N):
        graph.append(list(map(int, input().split())))

    dp(N,M,graph)
    #print(*graph, sep = '\n')
    print(sum(graph[0])%divide)
