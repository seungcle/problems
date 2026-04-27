from collections import deque

def strToInt(s1):
    h, m = s1.split(':')
    return int(h) * 60 + int(m)

def solution(plans):
    new_plans = []
    for name, start, playtime in plans:
        new_plans.append([name, strToInt(start), int(playtime)])
    new_plans.sort(key=lambda x: x[1])
    
    answer = []
    stack = [] 
    
    for i in range(len(new_plans)):
        if i == len(new_plans) - 1:
            answer.append(new_plans[i][0])
            break
        
        name, start, playtime = new_plans[i]
        next_name, next_start, next_playtime = new_plans[i+1]
        
        finish_time = start + playtime
        
        if finish_time <= next_start:
            answer.append(name)
            
            gap = next_start - finish_time
            while gap > 0 and stack:
                s_name, s_remained = stack.pop()
                if s_remained <= gap:
                    gap -= s_remained
                    answer.append(s_name)
                else:
                    stack.append([s_name, s_remained - gap])
                    gap = 0
                    
        else:
            stack.append([name, finish_time - next_start])
            
    while stack:
        answer.append(stack.pop()[0])
        
    return answer