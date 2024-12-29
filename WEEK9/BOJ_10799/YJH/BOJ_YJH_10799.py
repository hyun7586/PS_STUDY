import sys

input = sys.stdin.readline


if __name__ == "__main__":
    irons = list(input().rstrip())
    stack = []
    ans = 0

    for i in range(len(irons)):
        
        if irons[i] == '(':
            stack.append(irons[i])

        else:
            if irons[i-1] == '(':
                stack.pop()
                ans += len(stack)
            else:
                stack.pop()
                ans += 1

    print(ans)