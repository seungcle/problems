def solution(s):
    tmp = 0
    answer = ""
    for c in s:
        if c == ' ':
            answer += c
            tmp = 0
            continue
        if tmp == 0:
            answer += c.upper()
            tmp += 1
        else:
            answer += c.lower()
            tmp += 1
    return answer