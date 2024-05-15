import sys

input = sys.stdin.readline

if __name__ == "__main__":

    n = int(input())
    triangle = []
    dp = [[0 for k in range(i+1)] for i in range(n)]

    for i in range(n):    
        triangle.append(list(map(int,input().split())))

    #print(*triangle, sep = '\n');

    dp[0][0] = triangle[0][0]

    #print(*dp, sep = '\n')

    for i in range(1,n):
        for k in range(i+1):

            if k == 0:
                dp[i][k] = triangle[i][k] + dp[i-1][k]

            elif k == i:
                dp[i][k] = triangle[i][k] + dp[i-1][k-1]
            
            elif k == i:
                dp[i][k] = triangle[i][k] + dp[i-1][k-1]
            
            else:
                dp[i][k] = max(triangle[i][k] + dp[i-1][k-1], triangle[i][k] + dp[i-1][k])

    ans = max(dp[n-1])

    print(ans)
