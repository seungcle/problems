def solution(n):
    dp = [0] * 15
    dp[0] = 1
    dp[1] = 1
    for j in range(2,n+1):
        for i in range(0,j):
            dp[j] = dp[j] + dp[i] * dp[j-1-i]
    return dp[n]