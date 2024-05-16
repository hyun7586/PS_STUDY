    import sys

    input = sys.stdin.readline

    if __name__ == "__main__":

        n = int(input())
        dp = [0 for i in range(n)]
        wine = [0 for i in range(n)]

        for i in range(n):
            wine[i] = int(input())

        if n == 1:
            dp[0] = wine[0]

        elif n== 2:
            dp[0] = wine[0]
            dp[1] = wine[1] + dp[0]
        elif n == 3:
            dp[0] = wine[0]
            dp[1] = wine[1] + wine[0]
            dp[2] = max(dp[0]+wine[2],wine[1]+wine[2],dp[1])

        else:
            dp[0] = wine[0]
            dp[1] = wine[1] + dp[0]
            dp[2] = max(dp[0],wine[1]) + wine[2]

            for i in range(3,n):
                dp[i] = max(dp[i-2]+wine[i],dp[i-3]+wine[i-1]+wine[i],dp[i-1])

        print(dp[n-1])