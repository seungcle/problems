import math

def get_lcm(numbers):
    lcm = numbers[0]
    for i in range(1, len(numbers)):
        lcm = (lcm * numbers[i]) // math.gcd(lcm, numbers[i])
    return lcm

def solution(signals):
    cycles = [sum(s) for s in signals]
    max_time = get_lcm(cycles)
    
    for t in range(1, max_time + 1):
        all_yellow = True
        
        for i in range(len(signals)):
            G, Y, R = signals[i]
            T = cycles[i]
            
            current_pos = (t - 1) % T
            
            if not (G <= current_pos < G + Y):
                all_yellow = False
                break
        
        if all_yellow:
            return t
            
    return -1