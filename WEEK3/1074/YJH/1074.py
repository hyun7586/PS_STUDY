#1074
import sys

input = sys.stdin.readline


def dc(y,x,N,r,c):
    cnt = 0

    while N != 1:
        N = N//2

        if r < y + N and c < x + N:
            continue
        elif r < y + N and c >= x + N:
            x += N
            cnt += N*N
        elif r >= y + N and c < x + N:
            y += N
            cnt += 2*N*N
        elif r >= y + N and c >= x + N:
            x += N
            y += N
            cnt += 3*N*N

    return cnt
        
if __name__ == '__main__':
    N, r, c = map(int, input().split())

    print(dc(0,0,2**N,r,c))
