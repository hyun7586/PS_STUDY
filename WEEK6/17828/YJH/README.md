# 17828 : 문자열 화폐

## 코드 설명
1. 처음에 예외처리 ( N* 26 < X 이거나 N > X 이면 화폐 만들 수 없다)
2. 문자열 화폐 모두 Z로 채울 수 있다면 다 채우고 break
3. 모두 채울 수 없다면 몇개나 Z로 채울 수 있는지 for문 돌리면서 확인
4. 남은 부분은 1이나 1~25 까지의 수들로 채우기


## etc
1. 처음 풀때는 ans[] 배열에 문자 담으면서 로직 구성 -> 메모리 초과 (N범위가 500만)
2. A와 Z가 아닌 문자는 최대 1개밖에 안들어간다
3. 처음 풀었을때 위의 로직 완전 반대로 구성(A로 모두 채운후 나머지 문자로 채우기) -> ans[]에 담아서 sorted() 했는데
시간 초과, 이후 역출력 했지만 메모리 초과
4. sorted()는 필요할때만 쓰자 
