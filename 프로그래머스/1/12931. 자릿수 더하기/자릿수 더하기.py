def solution(n):
    ans = 0
    while n:
        ans = ans + n % 10
        n //= 10
    return ans