import sys
import heapq

down_heap = []  # 중앙값 이하 값 저장 (음수로 저장 -> 기본 heapq는 최소 기준이기 때문)
                #down_heap 에서 0번째 인덱스는 down_heap 중 가장 큰 값
up_heap = []  # 중앙값 초과 값 저장

n = int(sys.stdin.readline()) 

for _ in range(n):
    num = int(sys.stdin.readline())

    # 최대 힙에 먼저 값을 넣음
    if not down_heap or num <= -down_heap[0]:
        heapq.heappush(down_heap, -num)
    else:
        heapq.heappush(up_heap, num)

    # 힙 크기 조정
    if len(down_heap) > len(up_heap) + 1:
        heapq.heappush(up_heap, -heapq.heappop(down_heap))
    elif len(up_heap) > len(down_heap):
        heapq.heappush(down_heap, -heapq.heappop(up_heap))

    # 중앙값 출력
    print(-down_heap[0])
