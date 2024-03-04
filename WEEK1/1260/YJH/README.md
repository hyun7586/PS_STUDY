# 1260 : DFS와 BFS

## 코드 설명

1. adjacency list로 구현
2. 방문을 표시하는 visted array를 dfs쓸 때와 bfs쓸 때 각각 1개씩 만듦.
3. undirected graph이므로 인접한 노드들을 서로 추가함.
4. 가중치가 없는 unweighted graph를 탐색하므로, 똑같은 가중치를 가질때 숫자가 낮은 것부터 탐색하도록, 정렬하는 sorted함수를 사용함.
5. dfs를 구현할때 stack을 사용하지 않고 재귀함수로도 간단히 구현함.
