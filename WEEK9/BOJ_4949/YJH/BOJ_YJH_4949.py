import sys
from collections import deque

input = sys.stdin.readline

if __name__ == "__main__":

    while True:
        sentance = input().rstrip()
        queue = []

        if sentance == '.':
            break


        for word in sentance:
            if word == '(' or word == '[':
                queue.append(word)
                
            elif word == ')':
                if queue:
                    if queue[-1] == '(':
                        queue.pop()
                    else:
                        queue.append(word)

                else:
                    queue.append(word)
            elif word == ']':
                if queue:
                    if queue[-1] == '[':
                        queue.pop()
                    else:
                        queue.append(word)
                else:
                    queue.append(word)

        if queue :
            print("no")
        else:
            print("yes")      