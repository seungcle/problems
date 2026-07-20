from collections import deque

def solution(land):
    n = len(land)
    m = len(land[0])
    
    visited = [[False] * m for _ in range(n)]
    result = [0] * m
    
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]
    
    for i in range(n):
        for j in range(m):
            if land[i][j] == 1 and not visited[i][j]:
                queue = deque([(i, j)])
                visited[i][j] = True
                
                count = 0
                columns = set()
                
                while queue:
                    r, c = queue.popleft()
                    count += 1
                    columns.add(c)
                    
                    for d in range(4):
                        nr, nc = r + dr[d], c + dc[d]
                        if 0 <= nr < n and 0 <= nc < m:
                            if land[nr][nc] == 1 and not visited[nr][nc]:
                                visited[nr][nc] = True
                                queue.append((nr, nc))
                
                for col in columns:
                    result[col] += count
                    
    return max(result)