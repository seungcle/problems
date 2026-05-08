def solution(routes):
    answer = 1
    routes.sort(key=lambda x : x[1])
    cam = routes[0][1]
    for route in routes[1:]:
        if cam < route[0]:
            answer += 1
            cam = route[1]
            
    return answer