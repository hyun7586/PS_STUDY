import sys
import heapq

Array = []

N = int(sys.stdin.readline())
for _ in range(N):
    x = int(sys.stdin.readline()) 

    if x == 0 and Array == []:
        print('0')
    elif x != 0:
        heapq.heappush(Array, -x) #heapq 는 최소 힙 기준 이기 때문에 음수로 넣어서 최대힙으로 변환
    elif x == 0 and Array != []:
        print(-heapq.heappop(Array)) #Array 에 첫번째 인덱스가 최댓값이기에 출력 후 삭제
        
        

