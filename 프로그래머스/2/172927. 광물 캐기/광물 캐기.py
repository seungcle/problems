def solution(picks, minerals):
    total_picks = sum(picks)
    minerals = minerals[:total_picks * 5]
    
    groups = []
    for i in range(0, len(minerals), 5):
        group = minerals[i:i+5]
        groups.append([group.count("diamond"), group.count("iron"), group.count("stone")])
    
    groups.sort(key=lambda x: (x[0], x[1], x[2]), reverse=True)
    
    answer = 0
    for d, i, s in groups:
        if picks[0] > 0: 
            answer += (d + i + s) 
            picks[0] -= 1
        elif picks[1] > 0: 
            answer += (d * 5 + i + s) 
            picks[1] -= 1
        elif picks[2] > 0: 
            answer += (d * 25 + i * 5 + s) 
            picks[2] -= 1
        else:
            break
            
    return answer