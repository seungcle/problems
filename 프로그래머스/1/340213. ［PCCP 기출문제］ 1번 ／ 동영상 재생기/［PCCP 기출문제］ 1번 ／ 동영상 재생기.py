def intToSec(n):
    m = n // 60
    s = n % 60
    sec = ""
    if m < 10:
        sec = "0"
    sec += str(m) + ":" 
    if s < 10:
        sec += "0"
    sec += str(s)
    return sec

def secToInt(sec):
    n = (int(sec[0])*10+int(sec[1]))*60
    n = n + (int(sec[3])*10+int(sec[4]))
    return n
    
def solution(video_len, pos, op_start, op_end, commands):
    vlen = secToInt(video_len)
    p = secToInt(pos)
    start = secToInt(op_start)
    end = secToInt(op_end)
    
    if start <= p and p < end:
        p = end
    
    for c in commands:
        if c == "next":
            p += 10
            if p > vlen:
                p = vlen
        elif c == "prev":
            p -= 10
            if p < 0:
                p = 0
        if start <= p and p < end:
            p = end
    answer = intToSec(p)
    return answer