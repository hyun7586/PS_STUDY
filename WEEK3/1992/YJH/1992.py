#1074
import sys

input = sys.stdin.readline

def dq(start_y,start_x,w,map):

    num = map[start_y][start_x]

    for i in range(start_y,start_y+w):
        for k in range(start_x,start_x+w):

            if map[i][k] == num:
                continue

            else:
                w = w//2
                print('(', end = '')
                dq(start_y,start_x,w,map)
                dq(start_y,start_x+w,w,map)
                dq(start_y+w,start_x,w,map)
                dq(start_y+w,start_x+w,w,map)
                print(')',end = '')
                return

    print(map[start_y][start_x], end = '')

if __name__ == '__main__':
    w = int(input())
    video = []
    
    for i in range(w):
        video.append(input().rstrip())

    #print(*video, sep = '\n')
    dq(0,0,w,video)
