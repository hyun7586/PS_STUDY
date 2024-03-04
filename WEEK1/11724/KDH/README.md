# [11724] 연결요소의 개수

### 코드 설명

1. 해당 node를 방문했는지를 기록하는 visited[]가 필요함.
2. 각 node별로 bfs()를 실행시킨다.
   -> bfs() 탐색이 끝났다는 건 해당 node에 연결된 모든 node를 방문했다는 거임
   -> component 개수 +=1
3. adjacent matrix 작성할 때 directed graph/undirected graph 구분
4. 일반적인 bfs와 다르게 함수 시작 부분에서 start node를 방문했는지 먼저 체크해야 함.
