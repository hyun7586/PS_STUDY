from collections import deque #deque 를 사용하기 위하여

n = int(input())
balloons = list(map(int, input().split()))

deque_balloons = deque(enumerate(balloons, start=1))

result = []

# 첫 번째 풍선을 터뜨리기
while deque_balloons:
    index, value = deque_balloons.popleft()  # 풍선 번호와 값을 꺼냄
    result.append(index)  # 터진 풍선 번호 저장

    if not deque_balloons:
        break  # 모든 풍선이 터진 경우 종료

    # 풍선 내부 값만큼 이동 (양수면 오른쪽, 음수면 왼쪽)
    if value > 0:
        deque_balloons.rotate(-(value - 1))  # 현재 위치 포함했으므로 -1 보정
    else:
        deque_balloons.rotate(-value)  # 음수는 그대로 이동

print(*result) #result가 list 형태이기 때문에 요소만 출력하기 위해 *result 
