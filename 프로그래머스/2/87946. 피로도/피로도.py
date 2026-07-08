from itertools import permutations

def solution(k, dungeons):
    answer = 0
    for p in permutations(dungeons, len(dungeons)):
        current_k = k
        count = 0
        for minimum, consume in p:
            if current_k >= minimum:
                current_k -= consume
                count += 1
            else:
                break
        answer = max(answer, count)
    return answer