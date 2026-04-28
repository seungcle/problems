from collections import deque

def solution(n, computers):
    answer = 0
    visited = set()
    q = deque()
    
    for i in range(n):
        if i in visited:
            continue
        
        visited.add(i)
        answer += 1
        q.append(i)
        
        while q:
            # 큐에서 현재 컴퓨터 x를 꺼냄
            x = q.popleft() 
            
            for j in range(n):
                # x와 연결되어 있고(1), 아직 방문하지 않은 컴퓨터 j를 찾음
                if computers[x][j] == 1 and j not in visited:
                    visited.add(j)
                    q.append(j)
                    
    return answer