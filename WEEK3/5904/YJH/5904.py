import sys

input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input())
    start = 0 # index 
    cnt = 3 #moo의 처음 글자갯수
    ary = [cnt] # moo수열의 글자갯수 등록
    
    while ary[start] < N:
        cnt += 1
        ary.append(2*ary[start] + cnt)
        start += 1
    
    #print(ary,start, cnt)

    while True:

        if start >=1 and N >3: 
            if N < ary[start-1]:
                start -= 1
                cnt -= 1
    
            elif N >=ary[start-1] and N < ary[start-1] + cnt:
                N -= ary[start-1]
    
                if N == 1:
                    print('m')
                    break
    
                else:
                    print('o')
                    break
    
            else:
                N -= (ary[start-1] + cnt)
                start -=1
                cnt -= 1

        else:

            if N ==1:
                print('m')
                break
            
            else:
                print('o')
                break
