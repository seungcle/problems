from collections import defaultdict

def solution(tickets):
    graph = defaultdict(list)
    for start, end in tickets:
        graph[start].append(end)
    
    for start in graph:
        graph[start].sort(reverse=True)
        
    stack = ["ICN"]
    path = []
    
    while stack:
        top = stack[-1]
        if top not in graph or not graph[top]:
            path.append(stack.pop())
        else:
            stack.append(graph[top].pop())
            
    return path[::-1]