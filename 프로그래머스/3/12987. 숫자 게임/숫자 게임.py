def solution(A, B):
    A.sort()
    B.sort()
    
    a_idx = 0  
    b_idx = 0  
    ans = 0
    
    while b_idx < len(B):
        if B[b_idx] > A[a_idx]:
            ans += 1
            a_idx += 1  
            b_idx += 1  
        else:
            b_idx += 1
            
    return ans