from collections import deque

n = int(input())

queue = deque(reversed(deque(range(1, n + 1)))) # queue에 n+1 부터 1 까지 초기화
discarded = []

while len(queue) > 1:
    discarded.append(queue.pop())  # 가장 위의 카드를 버림
    queue.insert(0,queue.pop())     # 그다음 카드를 아래로 옮김

print(*discarded,queue[0])
