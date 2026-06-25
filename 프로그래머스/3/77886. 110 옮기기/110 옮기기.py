def solution(s):
    answer = []
    
    for string in s:
        stack = []
        count_110 = 0
        
        for char in string:
            if char == '0' and len(stack) >= 2 and stack[-1] == '1' and stack[-2] == '1':
                stack.pop()
                stack.pop()
                count_110 += 1
            else:
                stack.append(char)
        
        remain = "".join(stack)
        idx = remain.rfind('0')
        
        if idx == -1:
            res = "110" * count_110 + remain
        else:
            res = remain[:idx + 1] + "110" * count_110 + remain[idx + 1:]
            
        answer.append(res)
        
    return answer