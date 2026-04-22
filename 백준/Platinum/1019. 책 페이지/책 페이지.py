N = int(input())

arr = [0] * 10
num = 1

def add_digits(n, current_num):
    for i in str(n):
        arr[int(i)] += current_num

while N > 0:
    while N % 10 != 9 and N > 0:
        add_digits(N, num)
        N -= 1
    
    if N == 0:
        break
    
    for i in range(10):
        arr[i] += (N // 10 + 1) * num
    
    arr[0] -= num
    num *= 10
    N //= 10

print(*(arr))