# [5639] 이진 검색 트리

### 코드 설명

1. preorder에서 첫번째로 주어지는 원소는 root임.
2. root보다 작은 값들은 left subtree, root보다 큰 값들은 right subtree로 보냄.
3. PostOrder()를 출력하는 것과 똑같은 로직으로 재귀호출하면 됨.

### ETC

1. 파일 끝까지 입력을 받을 때는 cin.eof()보다 while(cin>>a)구문을 사용
