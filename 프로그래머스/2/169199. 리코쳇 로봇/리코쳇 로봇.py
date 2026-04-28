from collections import deque

def move(x, y, dx, dy, N, M, board):
    while True:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < M and board[nx][ny] != 'D':
            x, y = nx, ny
        else:
            break
    return x, y

def solution(board):
    N, M = len(board), len(board[0])
    queue = deque()
    visited = [[False] * M for _ in range(N)]
    
    for i in range(N):
        for j in range(M):
            if board[i][j] == 'R':
                queue.append((i, j, 0))
                visited[i][j] = True
                break

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    while queue:
        x, y, cnt = queue.popleft()
        
        if board[x][y] == 'G':
            return cnt
        
        for i in range(4):
            nx, ny = move(x, y, dx[i], dy[i], N, M, board)
            
            if not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx, ny, cnt + 1))
                
    return -1 