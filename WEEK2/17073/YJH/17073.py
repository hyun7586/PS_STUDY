#17573
import sys

input = sys.stdin.readline


if __name__ == '__main__':

    #물이 움직이지 않는다는 것은 루트노드에 있는 물이 리프노드로 다 흘러 갔다는 것을 의미함
    
    Node, W = map(int, input().split())
    tree = [[] for i in range(Node+1)]
    leaf = 0 # 리프노드의 개수
    
    for _ in range(Node-1):
        node1, node2 = map(int, input().split())
        tree[node1].append(node2)
        tree[node2].append(node1)

        #리프노드만 찾으려면 tree = [0 for i in range(Node+1)]
        #for _ in range(Node-1): a,b = map(int,input().split()) tree[a] += 1, tree[b] += 1
        # print(W/tree[2:].count(1))
  
    #print(tree)

    for i in range(2,Node+1):
        if len(tree[i]) == 1:
            leaf += 1

    ans = W/leaf

    print(ans)
