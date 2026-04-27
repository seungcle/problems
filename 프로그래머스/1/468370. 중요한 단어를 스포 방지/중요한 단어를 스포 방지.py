import re

def solution(message, spoiler_ranges):
    words_info = []
    curr_idx = 0
    for w in message.split(' '):
        start = curr_idx
        end = start + len(w) - 1
        words_info.append((w, start, end))
        curr_idx = end + 2
    
    safe_words = set()
    for word, w_s, w_e in words_info:
        is_spoiler = False
        for s_s, s_e in spoiler_ranges:
            if w_s <= s_e and w_e >= s_s:
                is_spoiler = True
                break
        if not is_spoiler:
            safe_words.add(word)

    important_count = 0
    discovered_spoilers = set()
    processed_word_indices = set()
    
    for s_s, s_e in spoiler_ranges:
        for idx, (word, w_s, w_e) in enumerate(words_info):
            if w_s <= s_e and w_e >= s_s:
                if idx not in processed_word_indices:
                    if word not in safe_words and word not in discovered_spoilers:
                        important_count += 1
                    discovered_spoilers.add(word)
                    processed_word_indices.add(idx)
                
    return important_count