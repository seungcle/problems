from collections import deque

def diff(s1, s2):
    cnt = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            cnt += 1
    return cnt == 1

def solution(begin, target, words):
    if target not in words:
        return 0

    q = deque([(begin, 0)])
    visited = {begin}

    while q:
        curr_word, step = q.popleft()

        if curr_word == target:
            return step

        for next_word in words:
            if next_word not in visited and diff(curr_word, next_word):
                visited.add(next_word)
                q.append((next_word, step + 1))

    return 0 