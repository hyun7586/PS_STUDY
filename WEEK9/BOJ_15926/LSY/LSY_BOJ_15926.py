def parentheses(n, s):
    stack = []  # 스택 초기화 (유효한 괄호 쌍의 인덱스 기록)
    max_length = 0
    last_invalid = -1  # 마지막으로 유효하지 않은 괄호의 인덱스

    for i in range(n):
        if s[i] == '(':
            stack.append(i)  # 여는 괄호의 인덱스를 스택에 추가
        else:
            if stack:
                stack.pop()  # 유효한 쌍을 만드므로 스택에서 제거
                if stack:
                    max_length = max(max_length, i - stack[-1])
                else:
                    max_length = max(max_length, i - last_invalid)
            else:
                last_invalid = i  # 유효하지 않은 닫는 괄호의 인덱스 업데이트

    return max_length

n = int(input())
s = input()

print(parentheses(n, s))
