import sys

input = sys.stdin.readline

global ans

ans = 0

def bt(depth, N, ary,record): #zero는 놓는 퀸의 수
    
    global ans

    #print(ary)

    if depth == N+1:
        ans += 1
        return

    else:
        for i in range(1,N+1):
            if ary[i] == 0: #만약 아무것도 없다면
                if depth == 1: #첫번째로 놓는거라면
                    ary[i] = depth #하나 놓기
                    record.append((depth,i))
                    bt(depth + 1, N, ary,record)
                    ary[i] = 0
                    record.pop()
                else: #첫번째로 놓는 것이 아니라면
                    count = 0
                    for k in range(len(record)):
                        if abs(depth-record[k][0]) != abs(i-record[k][1]):
                            count += 1

                    if count == len(record):
                        ary[i] = depth #하나 놓기
                        record.append((depth,i))
                        bt(depth + 1, N, ary,record)
                        ary[i] = 0
                        record.pop()
                        
                    else:
                        continue
                
if __name__ == "__main__":
    N = int(input())
    ary = [0 for i in range(N+1)]
    record = []
    bt(1,N,ary,record)
    print(ans)
