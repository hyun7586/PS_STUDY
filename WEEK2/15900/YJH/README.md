# 15900 : 나무 탈출

## 코드 설명

1. adjacency list로 tree구현
2. dep은 루트노드부터 각 노드까지의 높이를 표시하는 array
3. visited는 방문 표시하는 array
4. undirected tree로 구성
5. bfs를 통해 루트노드부터 각 노드까지의 높이를 dep array에 표시
6. 노드 중, 루트노드부터 리프노드까지의 거리만 모두 더해서 이 값이 짝수이면 win, 홀수이면 lose
7. ans는 루트노드부터 거리합계 표시
