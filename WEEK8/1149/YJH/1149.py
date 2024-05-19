    import sys

    input = sys.stdin.readline

    if __name__ == "__main__":
        N = int(input())
        ary = []
        dp = [[0 for i in range(3)] for k in range(N)]

        for i in range(N):
            ary.append(list(map(int,input().split())))


        #print(*ary,sep = '\n')

        dp[0][0] = ary[0][0]
        dp[0][1] = ary[0][1]
        dp[0][2] = ary[0][2]

        for i in range(1,N):
            for k in range(3):
                if k == 0:
                    dp[i][k] = min(dp[i-1][1],dp[i-1][2]) + ary[i][k]
                elif k == 1:
                    dp[i][k] = min(dp[i-1][0],dp[i-1][2]) + ary[i][k]
                elif k == 2:
                    dp[i][k] = min(dp[i-1][0],dp[i-1][1]) + ary[i][k]

        print(min(dp[N-1]))