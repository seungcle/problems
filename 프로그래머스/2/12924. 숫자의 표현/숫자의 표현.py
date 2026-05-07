def solution(n):
    answer = 1
    sumN = 0
    j = 0
    for i in range(n):
        sumN += i
        if sumN == n:
            answer += 1
        while sumN > n:
             sumN -= j
             j += 1
             if sumN == n:
                answer += 1
    return answer