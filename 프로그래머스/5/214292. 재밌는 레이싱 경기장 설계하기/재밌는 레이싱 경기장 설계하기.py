def solution(heights):
    heights.sort()
    n = len(heights)
    half = n // 2
    
    diffs = []
    for i in range(n - half):
        diffs.append(heights[i + half] - heights[i])
    
    diffs.sort()
    
    if n % 2 == 0:
        return diffs[0]
    else:
        return diffs[1]