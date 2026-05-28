def solution(cookie):
    answer = 0
    n = len(cookie)
    
    for m in range(n - 1):
        l = m
        r = m + 1
        
        left_sum = cookie[l]
        right_sum = cookie[r]
        
        while True:
            if left_sum == right_sum:
                answer = max(answer, left_sum)
                
                if l > 0 and r < n - 1:
                    l -= 1
                    r += 1
                    left_sum += cookie[l]
                    right_sum += cookie[r]
                else:
                    break
                    
            elif left_sum < right_sum:
                if l > 0:
                    l -= 1
                    left_sum += cookie[l]
                else:
                    break
            else:
                if r < n - 1:
                    r += 1
                    right_sum += cookie[r]
                else:
                    break
                    
    return answer