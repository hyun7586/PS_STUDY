#25977

import sys
from collections import deque

input = sys.stdin.readline

global apple
global pear

apple = 0
pear = 0

def bfs(tree, start ,Max_apple,visited,fruit_inf):
    global apple
    global pear
    queue = deque()
    queue.append(start)
    
    visited[start] = True

    if fruit_inf[start] == 1:
        apple += 1

    elif fruit_inf[start] == 2:
        pear += 1 
    

    while queue:
        move_node = queue.popleft()

        for node in tree[move_node]:

            if Max_apple == apple and fruit_inf[node] == 1 :
                continue
                # 사과를 최대치로 가졌는데도 더 가지려는 경우는 pass

            if not visited[node]:
                visited[node] = True
                queue.append(node)

                if fruit_inf[node] == 1:
                    apple += 1

                elif fruit_inf[node] == 2:
                    pear += 1         



if __name__ == '__main__':
    Node, Max_apple = map(int, input().split())
    tree = [[] for _ in range(Node)]
    visited = [False] * Node

    for _ in range(Node-1):
        node1, node2 = map(int, input().split())
        tree[node1].append(node2)
        tree[node2].append(node1)


    fruit_inf = list(map(int, input().split()))

    #print(tree)
    #print(fruit_inf)

    bfs(tree, 0 ,Max_apple,visited,fruit_inf)
    print(pear)
