def solution(elements):
    answer = set()
    e = len(elements)
    extended = elements * 2
    
    for k in range(1, e + 1):
        for i in range(e):
            answer.add(sum(extended[i:i+k]))
            
    return len(answer)