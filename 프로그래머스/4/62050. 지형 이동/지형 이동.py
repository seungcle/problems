from collections import deque

def find(parent, x):
    if parent[x] == x:
        return x
    parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    root_a = find(parent, a)
    root_b = find(parent, b)
    if root_a != root_b:
        parent[root_a] = root_b
        return True
    return False

def solution(land, height):
    n = len(land)
    group_map = [[0] * n for _ in range(n)]
    group_id = 0
    
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    for i in range(n):
        for j in range(n):
            if group_map[i][j] == 0:
                group_id += 1
                queue = deque([(i, j)])
                group_map[i][j] = group_id
                while queue:
                    x, y = queue.popleft()
                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]
                        if 0 <= nx < n and 0 <= ny < n and group_map[nx][ny] == 0:
                            if abs(land[x][y] - land[nx][ny]) <= height:
                                group_map[nx][ny] = group_id
                                queue.append((nx, ny))
                                
    edges = []
    for x in range(n):
        for y in range(n):
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < n and 0 <= ny < n:
                    if group_map[x][y] != group_map[nx][ny]:
                        cost = abs(land[x][y] - land[nx][ny])
                        edges.append((cost, group_map[x][y], group_map[nx][ny]))
                        
    edges.sort()
    
    parent = [i for i in range(group_id + 1)]
    answer = 0
    cnt = 0
    
    for cost, a, b in edges:
        if union(parent, a, b):
            answer += cost
            cnt += 1
            if cnt == group_id - 1:
                break
                
    return answer