def solution(tri):
    dp = [[0 for _ in range(len(tri))] for _ in range(len(tri))]
    dp[0][0] = tri[0][0]
    answer = 0
    for i in range(1,len(tri)):
        for j in range(len(tri[i])):
            if j == 0:
                dp[i][j] = dp[i-1][j] + tri[i][j]
            elif j == len(tri[i]) - 1:
                dp[i][j] = dp[i-1][j-1] + tri[i][j]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + tri[i][j]
    
    for n in dp[len(tri)-1]:
        answer = max(answer,n)
        
    return answer