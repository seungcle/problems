def solution(sticker):
    N = len(sticker)
     
    if N == 1:
        return sticker[0]
    if N == 2:
        return max(sticker[0], sticker[1])
    
    dp1 = [0] * N
    dp2 = [0] * N
    
    dp1[0] = sticker[0]
    dp1[1] = max(sticker[0], sticker[1])
    for i in range(2, N - 1):
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i])
        
    dp2[1] = sticker[1]
    for i in range(2, N):
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i])
        
    return max(dp1[N - 2], dp2[N - 1])