## BOJ 1655 가운데를 말해요

### 문제 요약 및 추상화
- N개 숫자를 하나씩 입력받는다.
- 입력받을 때마다 현재까지 입력된 배열에서 median 값을 계속해 출력한다.


### 풀이 전략
- 0.1초 안에 해결해야 하므로 숫자 입력받을 때마다 queue를 정렬, median 값 출력을 `O(n)`으로 해결해야 한다.
- `priority_queue`를 이용할 건데 median을 출력할 수 있어야 한다.
- `max_heap`과 `min_heap`을 둘 다 사용한다. `max_heap.top()`을 median이라고 정의하고,
    median보다 작은 값은 `max_heap`, median보다 큰 값은 `min_heap`에 저장한다.
- 숫자를 입력받을 때마다 적절한 queue에 넣는 조정과정을 거치고, median 값을 출력한다.
