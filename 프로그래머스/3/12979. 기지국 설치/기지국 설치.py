import math

def solution(n, stations, w):
    answer = 0
    coverage = 2 * w + 1
    current_pos = 1
    
    for s in stations:
        length = (s - w) - current_pos
        if length > 0:
            answer += math.ceil(length / coverage)
        current_pos = s + w + 1
        
    if current_pos <= n:
        length = n - current_pos + 1
        answer += math.ceil(length / coverage)

    return answer