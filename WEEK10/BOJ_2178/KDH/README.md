## BOJ 2178 미로 탐색

### 문제 요약 및 추상화
- 1과 0으로 이루어진 map이 주어짐(0이 벽, 1이 길)
- (1, 1)에서 (N, M)까지 이동할 수 있는 최소 이동 수를 출력함

### 풀이 전략
- map을 구성할 때 입력이 한 글자씩 떨어져서 주어지는 게 아니라 붙어서 주어진다는 걸 주의해서 입력을 받으면 된다.
- map을 구성하고 나면 기본적인 bfs로 순회하면 된다.
- 가장 먼저 도착점에 도착한 queue가 최적해가 된다.
