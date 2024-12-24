### BOJ 4949 균형잡힌 세상

#### 문제 요약 및 추상화
- 각 문장이 한 줄씩 주어지며 일반 문자, 괄호, '.'(온점)으로 구성되어있다.
- '.'(온점)을 기준으로 문장을 구분할 수 있다.
- 각 문장에서 괄호의 짝이 다 맞는 경우에는 yes, 그렇지 않은 경우에는 no를 출력한다.


#### 해결 전략
- 각 문장을 순회하며 마주치는 괄호를 stack에 저장하며 짝을 맞춘다.
- 열린 괄호(`(`, `[`)를 마주치면 stack에 저장하고,
- 닫힌 괄호(`)`, `]`)를 마주치면 현재 stack 최상단(`stack.top()`)에 위치한 원소와 짝이 맞는지 판단한다.
- 중간 로직을 만나면서 한 번도 false 조건을 만나지 않고 `.`에 도달했을 때 `stack.size()`가 0이라면 짝이 맞는 문장으로 판단한다.(yes를 출력한다.)



#### case 분리
if-else문 구조가 많이 겹쳐있어 case분리 기준을 간단히 나타냈다.
아래는 문장 순회 중 만날 수 있는 문자를 분류한 것이다.
각 문장의 최종 yes 판단은 항상 exit conditions에서만 한다. 문장 끝까지 가 봐야 판단할 수 있다.

- `.` : exit conditions, `stack.size()==0`이면 yes, 아니면 no
- `(`, `[` : 무조건 stack에 push
- `(`: `stack.top()==')'`이면 stack.pop & keep going, 그렇지 않다면 no 출력
- `[`: `stack.top()==']'`이면 stack.pop & keep going, 그렇지 않다면 no 출력
- 이외 다른 문자: 무시