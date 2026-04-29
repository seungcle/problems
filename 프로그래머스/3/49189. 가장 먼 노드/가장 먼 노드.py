from collections import deque

def solution(n, edge):
    graph = [[] for _ in range(n + 1)]
    for u, v in edge:
        graph[u].append(v)
        graph[v].append(u)
    
    distances = [0] * (n + 1)
    visited = [False] * (n + 1)
    
    q = deque([(1, 0)]) 
    visited[1] = True
    
    max_dist = 0
    
    while q:
        curr, dist = q.popleft() 
        distances[curr] = dist
        max_dist = max(max_dist, dist)
        
        for neighbor in graph[curr]: 
            if not visited[neighbor]:
                visited[neighbor] = True
                q.append((neighbor, dist + 1))
    
    return distances.count(max_dist)