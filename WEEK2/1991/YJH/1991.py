import sys

input = sys.stdin.readline


class Node:
    def __init__(self, data,left,right):
        self.data = data
        self.left = left
        self.right = right


def preorder(tree, word):
    print(tree[word].data, end='')
    
    if tree[word].left != '.':
        preorder(tree,tree[word].left)

    if tree[word].right != '.':
        preorder(tree,tree[word].right)
        
    
def inorder(tree, word):
    if tree[word].left != '.':
        inorder(tree,tree[word].left)

    print(tree[word].data, end='')

    if tree[word].right != '.':
        inorder(tree,tree[word].right)
        

def postorder(tree, word):
    if tree[word].left != '.':
        postorder(tree,tree[word].left)

    if tree[word].right != '.':
        postorder(tree,tree[word].right)

    print(tree[word].data, end='')


if __name__ == '__main__':
    N = int(input())
    tree = {}
    
    for i in range(N):
        data, left, right = input().split()

        tree[data] = Node(data, left, right)

    #for i in tree.keys():
    #    print(tree[i].data, tree[i].left, tree[i].right)

    preorder(tree,'A')
    print()
    inorder(tree,'A')
    print()
    postorder(tree,'A')
