def solution(n):
    bit = n & -n
    right = n + bit
    next_n = right | ((((n ^ right) >> 2) // bit))
    return next_n