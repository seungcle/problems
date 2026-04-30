import sys

sys.setrecursionlimit(100000)

def solution(k, room_number):
    answer = []
    room_map = {}

    def find_empty_room(number):
        if number not in room_map:
            room_map[number] = number + 1
            return number
        
        empty_room = find_empty_room(room_map[number])
        room_map[number] = empty_room + 1
        return empty_room

    for num in room_number:
        assigned_room = find_empty_room(num)
        answer.append(assigned_room)
        
    return answer