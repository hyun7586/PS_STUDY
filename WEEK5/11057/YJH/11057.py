import sys

input = sys.stdin.readline

if __name__ == "__main__":    

    N = int(input())
    ary = [[0 for i in range(10)] for k in range(N+1)]

    for i in range(10):
        ary[0][i] = 1

    for i in range(1,N+1):
        for k in range(10):
            for j in range(k,10):
                ary[i][k] += ary[i-1][j]

    print(sum(ary[N-1])%10007)
