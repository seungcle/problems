def solution(a, b):
    answer = ""
    if str(a)+str(b) > str(b) + str(a):
        answer = str(a)+str(b)
    else:
        answer = str(b)+str(a)
    answer = int(answer)
    return answer