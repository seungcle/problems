def solution(a, b, g, s, w, t):
    start = 0
    end = 10**14 * 4 
    answer = end

    while start <= end:
        mid = (start + end) // 2
        
        total_gold = 0
        total_silver = 0
        total_mineral = 0
        
        for i in range(len(g)):
            move_cnt = (mid + t[i]) // (t[i] * 2)
            max_w = move_cnt * w[i]
            total_gold += min(g[i], max_w)
            total_silver += min(s[i], max_w)
            total_mineral += min(g[i] + s[i], max_w)
        if total_gold >= a and total_silver >= b and total_mineral >= a + b:
            answer = mid
            end = mid - 1
        else:
            start = mid + 1
            
    return answer