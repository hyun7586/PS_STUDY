## LEET 347 Top K Frequent Elements

### 문제 요약 및 추상화
- 숫자를 원소로 하는 리스트가 주어진다.
- 각 숫자값 중 가장 빈출되는 상위 k개 항목을 출력한다.

### 풀이 전략
- 순서를 가지는 hash map을 사용해야 하므로 `map<int, int>`를 사용한다.
- 두 번째 int값을 기준으로 내림차순으로 정렬한 뒤 k개 record를 출력하면 된다.
