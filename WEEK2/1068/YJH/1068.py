#1068
from collections import deque
import sys

input = sys.stdin.readline

def bfs(tree,delete, visited,parent_node): # bfs로 삭제하려는 노드의 하위노드를 전부 방문표시
    queue = deque()
    queue.append(delete)
    visited[delete] = True

    while queue:
        move = queue.popleft()

        for node in tree[move]:

            if not visited[node]:
                visited[node] = True
                queue.append(node)

            #print(tree)
            #print(visited)


if __name__ == '__main__':
    Node = int(input())
    tree = [[] for _ in range(Node)]
    parent_node = list(map(int,input().split())) # 각 노드의 부모노드 표시
    delete = int(input()) # 삭제하려는 노드 입력
    root = 0 # 루트노드 표시하는 변수
    visited = [False] * Node # 방문 표시 나타내는 array
    ans = 0 # 리프노드 개수

    for i in range(Node):
        if parent_node[i] == -1:
            root = i
            continue

        tree[parent_node[i]].append(i) # 단방향 트리

    #print(tree)
 
    bfs(tree,delete, visited,parent_node)

    #print(tree)
    #print(visited)

    for i in range(Node):
        if not visited[i]: # 방문하지 않은 노드 중
            if len(tree[i]) == 0 : # 하위노드가 0개인 노드는 리프노드이다
                ans += 1

            if len(tree[i]) == 1 and delete in tree[i]: # 자식노드가 1개인데, 이 자식노드가 삭제하려는 노드일때 리프노드가 된다.  
                ans += 1                

    print(ans)
