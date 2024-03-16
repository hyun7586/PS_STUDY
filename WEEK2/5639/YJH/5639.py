import sys

input = sys.stdin.readline

sys.setrecursionlimit(10010) #최악의 경우 연산 10000번

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Bst:
    def __init__(self, head):
        self.head = head

    def insert_node(self,value):
        self.root = self.head

        while True: # bst insert 연산
            if self.root.data > value:
                if self.root.left != None:
                    self.root = self.root.left

                else:
                    self.root.left = Node(value)
                    break

            else:
                if self.root.right != None:
                    self.root = self.root.right
                
                else:
                    self.root.right = Node(value)
                    break


def post_order(root):
    if root.left != None:
        post_order(root.left)

    if root.right != None:
        post_order(root.right)

    print(root.data)


if __name__ == '__main__':

    li = [] #preorder로 순회한 결과 담는 list
    
    while True: #입력 받기 위해 try-except문 활용
        try:
            li.append(int(input()))

        except:
            break

    head = Node(li[0]) # 전위순회이므로 무조건 첫번째 원소가 root
    bst = Bst(head)

    for i in range(1,len(li)):
        bst.insert_node(li[i])

    post_order(head)
