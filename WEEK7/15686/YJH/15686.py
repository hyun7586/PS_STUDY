import sys
from itertools import combinations

input = sys.stdin.readline

if __name__ == "__main__":

    N, M = map(int, input().split())
    graph = []
    house = [] # 집 좌표 기록
    chicken = [] #치킨 집 좌표 기록
    nCr = []
    ans = int(1e9)
    
    for i in range(N):
        graph.append(list(map(int, input().split())))

        for k in range(N):
            if graph[i][k] == 2:
                chicken.append((i,k))

            if graph[i][k] == 1:
                house.append((i,k))

    
    record = [0 for i in range(len(house))]
    
    nCr = combinations(chicken,M)
    nCr = list(nCr)
    
    for cases in nCr:
        for case in range(len(cases)):
            for i in range(len(house)):
                if case == 0:
                    record[i] = abs(cases[case][0] - house[i][0]) + abs(cases[case][1] - house[i][1])
                else:
                    temp = abs(cases[case][0] - house[i][0]) + abs(cases[case][1] - house[i][1])
                    if temp < record[i]:
                        record[i] = temp

        if ans > sum(record):
            ans = sum(record)

    print(ans)
