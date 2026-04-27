import math

def solution(r1, r2):
    answer = 0
    for i in range(1,r2+1):
        y1= r1*r1 - i*i
        y2= r2*r2 - i*i
        if y1 < 0:
            y1 = 0
        else:
            y1 = math.sqrt(y1)
            y1 = math.ceil(y1)
        if y2 < 0:
            y2 = 0
        else:
            y2 = math.sqrt(y2)
            y2 = math.floor(y2)
        answer = answer + y2 - y1 + 1
    answer *= 4
    return answer