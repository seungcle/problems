def solution(brown, yellow):
    for h in range(1, int(yellow**0.5) + 1):
        if yellow % h == 0:
            w = yellow // h
            if 2 * (w + h) + 4 == brown:
                return [w + 2, h + 2]