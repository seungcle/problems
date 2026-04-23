def solution(targets):
    answer = 0
    targets.sort(key=lambda x: x[1])
    
    last_shot = -1
    
    for s, e in targets:
        if s >= last_shot:
            answer += 1
            last_shot = e
            
    return answer