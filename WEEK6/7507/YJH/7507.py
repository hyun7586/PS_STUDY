import sys

input = sys.stdin.readline

if __name__ == '__main__':
    T = int(input()) # number of testcase

    for i in range(T):
        N = int(input()) #number of battle
        ary = [[0 for _ in range(3)] for __ in range(N)]
        ans = 0 #정답
        date = 0 #일 기록
        start = 0
        end = 0
        
        for k in range(N):
            ary[k][0],ary[k][1],ary[k][2] = map(int, input().split())

        ary = sorted(ary)
        #print(*ary, sep = '\n')

        for k in range(N):

            if k == 0 :
                #print('case1')
                date = ary[k][0]
                start = ary[k][1]
                end = ary[k][2]
                ans += 1
            
            else:
                if ary[k][0] != date:
                    #print('case2')
                    ans += 1
                    date = ary[k][0]
                    start = ary[k][1] #새로운 날로 넘어왔을때는 start 와 end 초기화
                    end = ary[k][2]
                    continue
                    
                if ((start <= ary[k][1] < end) and (start < ary[k][2] < end)) or ((start < ary[k][1] < end) and(start < ary[k][2] <= end)):
                    #print('case3')
                    start= ary[k][1]
                    end = ary[k][2]

                elif end <= ary[k][1]:
                    #print('case4')
                    start = ary[k][1]
                    end = ary[k][2]
                    ans += 1

        if i == T-1:
            print(f"Scenario #{i+1}:\n{ans}")

        else:
            print(f"Scenario #{i+1}:\n{ans}\n")
