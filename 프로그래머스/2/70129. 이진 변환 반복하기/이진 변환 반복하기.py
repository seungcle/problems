def func1(s):
    k = len(s)
    s = ""
    while k != 0:
        tmp = k % 2
        k = k // 2
        s = s + str(tmp)
    return s

def solution(s):
    answer = []
    i = 0
    zero = 0
    while s != '1':
        tmp = ""
        for c in s:
            if c == '0':
                zero+= 1
            else:
                tmp += c
        s = func1(tmp)
        i += 1
    answer.append(i)
    answer.append(zero)
    return answer