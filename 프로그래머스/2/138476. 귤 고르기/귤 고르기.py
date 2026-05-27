def solution(k, tangerine):
    answer = 0
    dict_t = {}
    for n in tangerine:
        if n in dict_t:
            dict_t[n] += 1
        else:
            dict_t[n] = 1
    sorted_dict = dict(sorted(dict_t.items(), key=lambda x: x[1], reverse=True))
    for v in sorted_dict.values():
        k = k - v
        answer += 1
        if k <= 0:
            break
    return answer