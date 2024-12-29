from collections import deque
import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    queue = deque([i for i in range(1,N+1)])
    ans = []

    while True:
        remove = queue.popleft()
        ans.append(remove)

        if not queue:
            break
        top = queue[0]
        queue.append(top)
        queue.popleft()

    print(*ans)