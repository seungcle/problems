def solution(code):
    answer = ''
    mode = 0
    for i, c in enumerate(code):
        if mode == 0:
            if c != '1':
                if i % 2 == 0:
                    answer += c
            else: 
                mode = 1
        elif mode == 1: 
            if c != '1':
                if i % 2 == 1:
                    answer += c
            else:
                mode = 0
                
    return answer if answer != '' else "EMPTY"