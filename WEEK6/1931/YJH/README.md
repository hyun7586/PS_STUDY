# [1931] : 회의실 배정

## 코드 설명

0. ans variable은 회의실 최대개수 기록하는 변수
1. col이 2이고 row가 N인 ary 배열 생성 (회의 시작시간과 종료 시간 기록)
2. ary 배열 정렬
3. for문을 통해 ary 배열을 순회(start와 end의 초기값은 index가 0일때로 설정) 
4. 순회 중 회의 시작시간(ary[i][0)과 종료 시간(ary[i][1])이 start와 end 값 사이에 있다면 start와 end값 변경
   - 시간이 더 적게 걸리는 회의로 변경하는 과정  
5. end값보다 ary[i][0]값이 크다면 start값과 end값 변경 후 ans += 1( start = ary[i][0], end = ary[i][1])
   - 이전까지의 회의에서는 최적의 값 탐색 완료

## etc
1. 처음에 시간이 더 적게 걸리는 회의의 조건을 쓸 때, (start <= ary[i][0] and ary[i][1] < end)and (start < ary[i][0] and ary[i][1] <= end)라고 써서 틀림
2. ary[i][0]값은 항상 end보다 작아야하며, ary[i][1] 값은 항상 start보다 커야한다.

## 반례
3
2 4
3 4
4 4
