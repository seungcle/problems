def solution(arr, k):
    answer = []
    left = 0
    current_sum = 0
    
    for right in range(len(arr)):
        current_sum += arr[right]
        
        while current_sum > k and left <= right:
            current_sum -= arr[left]
            left += 1
            
        if current_sum == k:
            if answer == []:
                answer = [left, right]
            elif answer[1] - answer[0] > right - left:
                answer = [left, right]
    return answer