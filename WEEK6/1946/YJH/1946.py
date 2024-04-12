import sys

input = sys.stdin.readline

if __name__ == '__main__':
    T = int(input())

    for i in range(T):
        N = int(input())
        ary = [0] * (N+1)
        m = int(1e9) # 최솟값 기록
        ans = 0 # 정답
        
        for k in range(1,N+1):
            x,y = map(int, input().split())
            ary[x] = y
        
        for k in range(1,N+1):
            if m > ary[k]:
                ans += 1
                m = ary[k]

        #print(*ary, sep = '\n')
        print(ans)
