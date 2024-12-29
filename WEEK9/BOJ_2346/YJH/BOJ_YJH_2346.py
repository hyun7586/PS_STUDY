from collections import deque
import sys

input = sys.stdin.readline


if __name__ == "__main__":

    queue = deque([1,2,3,4,5])

    print(queue.popleft())
    
    print(queue.popleft())