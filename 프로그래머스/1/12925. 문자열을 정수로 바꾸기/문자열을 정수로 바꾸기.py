def solution(s):
    ans = 0
    tmp = 0
    for c in s:
        if c == '-':
           tmp = -1 
        elif c == '+':
            continue
        else:
            ans = ans * 10 + int(c)
    if tmp == -1:
        ans = ans * -1
    return ans