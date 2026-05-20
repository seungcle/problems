def solution(user_id, banned_id):
    unique_ban_sets = set()
    
    def is_match(user, ban):
        if len(user) != len(ban):
            return False
        for u, b in zip(user, ban):
            if b != '*' and u != b:
                return False
        return True

    def dfs(n, picked):
        if n == len(banned_id):
            unique_ban_sets.add(tuple(sorted(picked)))
            return

        current_ban = banned_id[n]
        
        for user in user_id:
            if user in picked:
                continue
                
            if is_match(user, current_ban):
                picked.append(user)
                dfs(n + 1, picked)
                picked.pop() 
    dfs(0, [])
    
    return len(unique_ban_sets)