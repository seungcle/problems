def solution(mats, park):
    h = len(park)
    w = len(park[0])
    dp = [[0] * w for _ in range(h)]
    max_sq = 0
    
    for i in range(h):
        for j in range(w):
            if park[i][j] == "-1":
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                if dp[i][j] > max_sq:
                    max_sq = dp[i][j]
    
    mats.sort(reverse=True) 
    for m in mats:
        if m <= max_sq: 
            return m
            
    return -1