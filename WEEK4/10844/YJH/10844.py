#5904
import sys

input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input())
    ary = [[0 for i in range(10)] for k in range(N+1)]
    INF = 1000000000

    for i in range(1,10):
        ary[0][i] = 1
    ary[0][0] = 0

    for i in range(1,N+1):
        for k in range(10):
            if k == 0:
                ary[i][k] = ary[i-1][k+1]

            elif k == 9 :
                ary[i][k] = ary[i-1][k-1]

            else:
                ary[i][k] = ary[i-1][k-1] + ary[i-1][k+1]

    print(sum(ary[N-1])%INF)
