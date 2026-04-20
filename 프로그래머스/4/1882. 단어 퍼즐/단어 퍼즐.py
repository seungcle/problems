def solution(strs, t):
    answer = 0
    n = len(t)
    dp = [float('inf')] * (n + 1)
    dp[0] = 0
    
    strs_set = set(strs)
    for i in range(1,n+1):
        for k in range(1,6):
            if i - k < 0: 
                break
            sub = t[i-k:i]
            if sub in strs_set:
                dp[i] = min(dp[i],dp[i-k]+1)
    answer = dp[n]
    if answer == float('inf'):
        return -1
    else:
        return answer