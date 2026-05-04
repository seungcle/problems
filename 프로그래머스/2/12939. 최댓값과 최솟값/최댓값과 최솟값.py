def solution(s):
    list_num = s.split()
    list_num = [int(x) for x in list_num]
    answer = f"{min(list_num)} {max(list_num)}"
    return answer