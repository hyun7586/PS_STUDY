# [1068] 트리

### 코드 설명

1. vector<int> arr_child는 해당 노드의 child를 기록하는 vector임.
   - arr_child[x]==y -> node x의 child가 y임.
2. 모든 탐색은 dfs를 활용
3. deleting node는 arr_child[x]에서 y 원소를 삭제하는 식으로 해결함.

### 반례, 주의점

1. root node가 0이 아닐 때도 있음.
2. root node가 delete될 때도 고려해야 함.
3. root node만 남는 경우도 고려해야 함.
