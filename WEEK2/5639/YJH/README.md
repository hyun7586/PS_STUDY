# 5639 : 이진 검색

## 코드 설명

1. 연결리스트(class)로 노드 구성 ( data, left, right)
2. BST + 삽입을 구현하는 문제
3. li array에 try-except문을 통해서 preorder을 거친 값들을 추가.
4. preorder을 돌렸을때 가장 첫번째 값이 root노드이므로 li[0]을 root노드로 생성
5. 이후 li의 length만큼 for문 돌리면서 BST Tree에 insert 한후 post-order(왼-오-방문)
6. BST insert 함수에서 head node를 root variable에 복사해서 삽입할때 사용
7. 재귀함수를 이용하므로 최악의 상황(10000번)도 거뜬히 돌아가도록 setrecursionlimit 한계를 10001로 설정
