import sys

input = sys.stdin.readline

global ans

ans= 0 #정답

def bt(start,N, ary,sum):
    global ans
    
    if start == N:
        if sum >0 and sum%3 == 0:
            ans += 1
            return
        return

    else:
        if start == 0:
            for i in range(1,3):
                sum += ary[i]
                bt(start+1,N,ary,sum)
                sum -= ary[i]
        else:
            for i in range(3):
                sum += ary[i]
                bt(start+1,N,ary,sum)
                sum -= ary[i]

if __name__ == "__main__":
    N = int(input())
    ary = [0,1,2]
    start = 0 # 자리 수 측정하는 변수
    sum = 0
    
    bt(start,N,ary,sum)

    print(ans)
