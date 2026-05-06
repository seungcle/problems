def solution(m, n, puddles):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for px, py in puddles:
        dp[py][px] = -1
    
    dp[1][1] = 1
    
    for y in range(1, n + 1):
        for x in range(1, m + 1):
            if (x == 1 and y == 1) or dp[y][x] == -1:
                continue
            
            top = dp[y-1][x] if dp[y-1][x] != -1 else 0
            left = dp[y][x-1] if dp[y][x-1] != -1 else 0
            
            dp[y][x] = (top + left) % 1000000007
            
    return dp[n][m]