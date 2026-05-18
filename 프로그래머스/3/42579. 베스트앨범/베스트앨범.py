def solution(genres, plays):
    answer = []
    total = {}
    songs = {}
    
    for i, (g, p) in enumerate(zip(genres, plays)):
        if g not in total:
            total[g] = 0
            songs[g] = []
        total[g] += p
        songs[g].append((i, p))
        
    for g, _ in sorted(total.items(), key=lambda x: x[1], reverse=True):
        for s in sorted(songs[g], key=lambda x: (-x[1], x[0]))[:2]:
            answer.append(s[0])
            
    return answer