def solution(stones, k):
    left = 1
    right = max(stones) 
    answer = 0
    
    while left <= right:
        mid = (left + right) // 2  
        
        cannot_cross_count = 0
        possible = True
        
        for stone in stones:
            if stone < mid: 
                cannot_cross_count += 1
                if cannot_cross_count >= k:
                    possible = False
                    break
            else:
                cannot_cross_count = 0  
                
        if possible:
            answer = mid
            left = mid + 1
        else:
            right = mid - 1
            
    return answer