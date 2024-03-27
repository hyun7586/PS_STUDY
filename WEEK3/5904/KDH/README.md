# [5904] Moo 게임

### 코드 설명

1. moo string을 직접적으로 메모리에 저장해서 index에 따라 return할 수는 없다. string의 길이를 이용해야 한다.
2. moo string의 길이에도 규칙이 있다 : len(k)=len(k-1)+k+3+len(k-1)
3. input으로 받아온 index가 moo string 중 어느 부분에 속하는지 판단한 뒤, recursion
