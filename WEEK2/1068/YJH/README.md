# 1068 : 트리

## 코드 설명

1. adjacent list로 트리 구성, parent_node에는 각 인덱스에 해당하는 노드의 부모 노드를 표시
2. delete는 삭제할 노드의 입력받는 변수
3. root는 parent_node에서 값이 -1인 root노드를 찾아내는 변수 -> 딱히 쓸모는 없다.
4. visited는 방문 표시 하는 array
5. directed tree로 구성 -> undirected,directed 두 방식 다 가능
6. bfs를 통해 delete 노드의 하위노드 전부 방문표시 
7. (방문표시 안되어있는 노드 + 노드 안 원소가 0개인 노드) + (방문표시 안되어있는 노드 + 노드 안 원소가 1개지만 그게 delete 노드인 경우) leaf node로 판단
8. ans에 리프노드 표시  
