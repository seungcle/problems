def solution(gems):
    gem_types_count = len(set(gems))
    gems_len = len(gems)
    
    answer = [1, gems_len] 
    gem_dict = {}
    start = 0
    
    for end in range(gems_len):
        gem_dict[gems[end]] = gem_dict.get(gems[end], 0) + 1
        
        while len(gem_dict) == gem_types_count:
            if (end - start) < (answer[1] - answer[0]):
                answer = [start + 1, end + 1]
            
            gem_dict[gems[start]] -= 1
            if gem_dict[gems[start]] == 0:
                del gem_dict[gems[start]]
                
            start += 1
            
    return answer