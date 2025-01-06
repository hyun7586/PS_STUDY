def dijkstra(N, graph, start, end):
    # 최대 비용을 설정 
    max_cost = 1000000000
  #max_cost 가 값이 문제에서 주어진 100,000만 넘으면 되지 않나? 왜 100,000이 안되는 걸까
    # 최소 비용을 저장하는 리스트
    distance = [max_cost] * (N + 1)
    distance[start] = 0
    
    visited = [False] * (N + 1)  # 방문 여부를 체크하는 리스트
    
    for _ in range(N):
        # 아직 방문하지 않은 도시 중 최소 비용을 가진 도시 찾기
        min_cost = max_cost
        min_city = -1
        for city in range(1, N + 1):
            if not visited[city] and distance[city] < min_cost:
                min_cost = distance[city]
                min_city = city
        
        # 더 이상 갈 수 있는 도시가 없으면 종료
        if min_city == -1:
            break
        
        # 선택된 도시를 방문 처리
        visited[min_city] = True
        
        # 선택된 도시에서 갈 수 있는 다른 도시들에 대해 최소 비용 갱신
        for next_cost, next_city in graph[min_city]:
            if distance[next_city] > distance[min_city] + next_cost:
                distance[next_city] = distance[min_city] + next_cost
    
    return distance[end]


N = int(input())  # 도시의 개수
M = int(input())  # 버스의 개수
    
    # 그래프 초기화
graph = [[] for _ in range(N + 1)]
    
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))  # 출발도시 u에서 도착도시 v까지 가는 비용 w
    
start, end = map(int, input().split())
    
# Dijkstra 알고리즘을 이용해서 최소 비용을 구함
result = dijkstra(N, graph, start, end)
    
print(result)
