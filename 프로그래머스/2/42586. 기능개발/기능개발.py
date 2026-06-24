from collections import deque
import math

def solution(progresses, speeds):
    answer = []
    days = deque()
    
    for p, s in zip(progresses, speeds):
        days.append(math.ceil((100 - p) / s))
    
    while days:
        current = days.popleft()
        count = 1
        
        while days and days[0] <= current:
            days.popleft()
            count += 1
            
        answer.append(count)
        
    return answer