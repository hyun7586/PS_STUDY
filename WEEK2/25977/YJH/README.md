# 25977 : k개 사과 트리 노드만으로 배를 최대로 수확하기

## 코드설명 

1. tree를 adjacent list로 구현
2. undirected tree 로 구성 -> directed tree로 구성해도 상관x
3. fruit_inf list에는 각 노드의 정보가 들어가있다 (사과 존재 : 1 , 배 존재 : 2, 아무것도 존재x : 0)
4. 사과의 개수, 배의 개수는 apple과 pear이란 전역변수로 정의(global)
5. bfs로 루트노드부터 탐색. Max_apple이 될때까지 일단 사과를 수집하고, 그다음 배를 수집하도록 알고리즘 구성(greedy algorithm)
6. 사과를 Max_apple만큼 가졌는데도 더 가지려고 하는 경우에는 예외처리(continue)
