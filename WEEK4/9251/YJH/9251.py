import sys

input = sys.stdin.readline

if __name__ == '__main__':
    str1 = list(input().rstrip())
    str2 = list(input().rstrip())

    ary = [[0 for i in range(len(str1))] for k in range(len(str2))]

    for i in range(len(str2)):
        for k in range(len(str1)):
            if str2[i] == str1[k]:
                if i == 0 :
                    ary[i][k] += 1
                        
                else:
                    if k == 0 :
                        ary[i][k] +=1 
                    else:
                        ary[i][k] = max(ary[i-1][k-1]+1,ary[i-1][k])
            
            else:
                if k == 0 :
                    ary[i][k] = ary[i-1][k]

                else:
                    ary[i][k] = max(ary[i-1][k], ary[i][k-1])
            
    #print(*ary, sep = '\n')
    print(ary[len(str2)-1][len(str1)-1])
