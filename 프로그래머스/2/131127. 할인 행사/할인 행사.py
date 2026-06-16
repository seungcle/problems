from collections import Counter

def solution(want, number, discount):
    answer = 0
    want_dict = {w: n for w, n in zip(want, number)}
    current_dict = Counter(discount[:10])
    
    if current_dict == want_dict:
        answer += 1
        
    for i in range(10, len(discount)):
        prev_item = discount[i - 10]
        current_dict[prev_item] -= 1
        if current_dict[prev_item] == 0:
            del current_dict[prev_item]
            
        next_item = discount[i]
        current_dict[next_item] += 1
        
        if current_dict == want_dict:
            answer += 1
            
    return answer