#1931
import sys

input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input()) #회의의 개수
    ary = [[0 for i in range(2)] for k in range(N)] # 회의 각 시간 기록
    ans = 0 # 정답
    
    for i in range(N):
        ary[i][0], ary[i][1] = map(int, input().split())

    ary = sorted(ary)

    start = 0
    end = 0

    for i in range(N):
        if i == 0:
            #print('case1')
            start = ary[i][0]
            end = ary[i][1]
            ans += 1

        else:
            if (start<=ary[i][0]<end and start<ary[i][1]<end) or (start<ary[i][0]<end and start<ary[i][1]<=end):
                #print('case2')
                start = ary[i][0]
                end = ary[i][1]

            elif end <= ary[i][0]:
                #print('case3')
                start = ary[i][0]
                end = ary[i][1]
                ans += 1

        #print(start,end)
        
    print(ans)
