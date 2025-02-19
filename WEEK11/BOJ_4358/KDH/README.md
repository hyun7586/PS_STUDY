## BOJ 4358 생태학

### 문제 요약 및 추상화
- 심어진 나무 이름이 한 줄씩 주어짐
- 나무 종류에 따라 몇 그루가 심어졌는지 백분율로 출력해야 함.

### 풀이 전략
- 각 나무 이름, 심어진 횟수를 저장하는 map을 만듦(hash map)
- `map<string, int>`는 자동으로 string의 아스키코드상 오름차순으로 원소들을 정렬하기 때문에 map 원소를 하나씩 출력하면 된다.
- 주의해야 할 점 1: 소수점 아래 4째자리까지 출력(소숫점 아래 5째자리에서 반올림)
- 주의해야 할 점 2: `cin.eof()`는 입력스트림이 완전히 끝났을 때 true를 반환함. 마지막 입력 이후 불필요한 공백을 입력받았을 수도 있어서 이에 대한 예외처리가 필요함. 처음부터 `cin.eof()`를 쓰지 말든가, 공백을 받았으면 `continue;`시키는 식으로 처리해 줘야 함.