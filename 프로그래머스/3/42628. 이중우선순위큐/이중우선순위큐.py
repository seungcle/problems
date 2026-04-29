import heapq

def solution(operations):
    min_h = []
    max_h = []
    visited = [False] * 1000001 
    
    for i, op in enumerate(operations):
        command, num = op.split()
        num = int(num)
        
        if command == 'I':
            heapq.heappush(min_h, (num, i))
            heapq.heappush(max_h, (-num, i))
            visited[i] = True
            
        elif num == 1:
            while max_h and not visited[max_h[0][1]]:
                heapq.heappop(max_h)
            if max_h:
                visited[max_h[0][1]] = False
                heapq.heappop(max_h)
        else:
            while min_h and not visited[min_h[0][1]]:
                heapq.heappop(min_h)
            if min_h:
                visited[min_h[0][1]] = False
                heapq.heappop(min_h)
    
    while min_h and not visited[min_h[0][1]]:
        heapq.heappop(min_h)
    while max_h and not visited[max_h[0][1]]:
        heapq.heappop(max_h)
    
    if not min_h:
        return [0, 0]
    
    return [-max_h[0][0], min_h[0][0]]