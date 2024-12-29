def count_cut_pieces(stick):
    stack = []
    pieces = 0

    for i in range(len(stick)):
        if stick[i] == '(':
            stack.append('(')
        else:  
            stack.pop()
            if stick[i - 1] == '(':
                pieces += len(stack)
            else:
                pieces += 1

    return pieces

stick = input()
print(count_cut_pieces(stick))
