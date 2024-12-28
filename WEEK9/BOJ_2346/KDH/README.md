### KDH: BOJ 2346 풍선 터뜨리기

#### 문제 요약 및 추상화
- 각 풍선에는 다음 풍선으로 이동할 수가 적혀있음.
- 현재 풍선을 터뜨린 후에 현재 풍선에 적힌 수만큼 이동하면 됨.(양수면 오른쪽, 음수면 왼쪽, 0은 나오지 않음)
- 방문하게 되는 풍선의 index를 순서대로 출력(index는 1부터 시작함)

#### 풀이 전략
- `deque<pair<index, value>>` 자료구조를 사용했다.
- 풍선을 터뜨리는 위치는 항상 `deque.front()`에서 터뜨린다.(deque의 첫번째 자리에서 항상 터뜨린다)
- `deque.front()` 위치에서 현재 풍선을 터뜨리고 index를 출력한 다음 풍선이 `deque.front()`에 올 때까지 deque를 회전시킨다.
- 현재 풍선의 value가 양수라면 오른쪽으로 회전(`deque.front()`를 `deque.back()`으로 이동), 음수라면 왼쪽으로 회전(`deque.back()`를 `deque.front()`으로 이동)