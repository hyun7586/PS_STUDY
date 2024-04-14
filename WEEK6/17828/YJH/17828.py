import sys

input = sys.stdin.readline

if __name__ == '__main__':
    N, X = map(int, input().split())
    n = N
    
    alphabet = {1 : 'A' , 2 : 'B', 3 : 'C', 4 : 'D', 5 : 'E', 6 :'F', 7 : 'G', 8 : 'H', 9 : 'I', 10 : 'J', 11 : 'K', 12 :'L',13:'M',14:'N',15:'O',16:'P',17:'Q',18:'R',19:'S',20:'T',21:'U',22:'V',23:'W',24:'X',25:'Y',26:'Z'}

    while N>0:

        #print(N,X)
        if N*26 < X or N > X: # 이 경우 만들수 없다.
            print('!')
            break

        else:
            if N*26 == X: # 남은 자리 Z로 모두 채울 수 있다면 채우고 break
                #print('case1')
                #ans.append(alphabet[1])
                print(alphabet[26]*N,sep='',end='')
                N -= N
                X -= 26*N
                break
    
            else: # 모두 Z로 채울 수 없다면
                if (X-(26*(N-1))) in alphabet.keys(): # 1~25 사이의 문자로 채우기.
                    #print('case2')
                    #ans.append(alphabet[X-N+1])
                    print(alphabet[(X-(26*(N-1)))],sep='',end='')
                    X -= (X-(26*(N-1)))
                    N -= 1
                else: # 1로 채우거나
                    #print('case3')
                    #ans.append(alphabet[1])
                    print(alphabet[1],sep='',end='')
                    N -= 1
                    X -= 1
