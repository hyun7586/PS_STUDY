import sys
from collections import deque

input = sys.stdin.readline


def bfs(tree, node_num, visited, dep): # 각 노드까지의 거리 재기 위해서 bfs사용

    queue = deque()
    queue.append(node_num)
    
    while queue:
        que = queue.popleft()
        visited[que-1] = True

        for node in tree[que]:
            if not visited[node-1]:
                visited[node-1] = True
                queue.append(node)
                dep[node] = dep[que] + 1
        
       

if __name__ == '__main__':
    Node = int(input())
    tree = [[] for i in range(Node+1)]
    dep = [0 for i in range(Node+1)] #루트 노드부터 거리 저장하는 array
    visited = [False] * (Node *1)
    ans = 0 

    for i in range(Node-1):
        node1,node2 = map(int, input().split()) #양방향 트리로 구성
        tree[node1].append(node2)
        tree[node2].append(node1)


    bfs(tree,1,visited,dep)

    for i in range(len(tree)):
        if len(tree[i]) == 1: #원소가 하나밖에 없다면 리프노드로 판단
            ans += dep[i] # 리프노드까지의 전체 길이 판단

    if ans % 2== 0: # 짝수면 lose
        print('No')
    else: # 홀수면 win
        print('Yes')    
